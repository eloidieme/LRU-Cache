#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./hashtable.h"

unsigned int hash(char* str, int tableSize)
{
	int length = strlen(str);
	unsigned int hash_value = 0;
	for (int i = 0; i < length; i++)
	{
		hash_value += str[i];
		hash_value = (hash_value * str[i]) % tableSize;
	}
	return hash_value;
}

tableNode** hashTableInit(int tableSize) {
	tableNode** hashTable = (tableNode**)calloc(sizeof(tableNode), tableSize);
	for (int i = 0; i < tableSize; i++) {
		hashTable[i] = NULL;
	}
	return hashTable;
}

void hashTableFillFromDll(tableNode** hashTable, dll* dllHead) {
	int tableSize = dllLength(dllHead);
	dll* current = dllHead;
	while (current->next) {
		hashTableInsert(hashTable, tableSize, current);
		current = current->next;
	}
	hashTableInsert(hashTable, tableSize, current);
	if (dllHead->prev) {
		current = dllHead->prev;
		while (current->prev) {
			hashTableInsert(hashTable, tableSize, current);
			current = current->prev;
		}
		hashTableInsert(hashTable, tableSize, current);
	}
}

void hashTablePrint(tableNode** hashTable, int tableSize) {
	printf("START\n");
	for (int i = 0; i < tableSize; i++) {
		if (hashTable[i] == NULL) {
			printf("\t%i\t---\n", i);
		} else {
			printf("\t%i\t", i);
			tableNode* tmp = hashTable[i];
			while (tmp != NULL)
			{
				printf("%s - ", hashTable[i]->dllist->val);
				tmp = tmp->nextNode;
			}
			printf("\n");
		}
	}
	printf("END\n");
}

void hashTableInsert(tableNode** hashTable, int tableSize, dll* node) {
	tableNode* tbNode = (tableNode*)malloc(sizeof(tableNode));
	tbNode->dllist = node;
	tbNode->nextNode = NULL;
	int index = hash(node->val, tableSize);
	tbNode->nextNode = hashTable[index];
	hashTable[index] = tbNode;
}

dll* hashTableLookup(tableNode** hashTable, int tableSize, char* str) {
	int index = hash(str, tableSize);
	tableNode* tmp = hashTable[index];
	while (tmp != NULL && strcmp(tmp->dllist->val, str) != 0) {
		tmp = tmp->nextNode;
	}
	return tmp->dllist;
}

void hashTableDelete(tableNode** hashTable, int tableSize, char* str) {
	int index = hash(str, tableSize);
	tableNode* tmp = hashTable[index];
	tableNode* prev = NULL;
	while (tmp != NULL && strcmp(tmp->dllist->val, str) != 0) {
		prev = tmp;
		tmp = tmp->nextNode;
	}
	if (tmp == NULL) return;
	if (prev == NULL) {
		hashTable[index] = tmp->nextNode;
	} else {
		prev->nextNode = tmp->nextNode;
	}
}

void hashTableDestroy(tableNode** hashTable) {
	free(hashTable);
}