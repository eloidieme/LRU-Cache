#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include "./dll.h"

typedef struct tableNode {
    dll* dllist;
    struct tableNode* nextNode;
} tableNode;

unsigned int hash(char* str, int tableSize);
tableNode** hashTableInit(int tableSize);
void hashTableFillFromDll(tableNode** hashTable, dll* dllHead);
void hashTablePrint(tableNode** hashTable, int tableSize);
void hashTableInsert(tableNode** hashTable, int tableSize, dll* node);
dll* hashTableLookup(tableNode** hashTable, int tableSize, char* str);
void hashTableDelete(tableNode** hashTable, int tableSize, char* str);
void hashTableDestroy(tableNode** hashTable);

#endif