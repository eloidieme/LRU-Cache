#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./dll.h"

void dllAppend(dll* head, const char* str) {
  dll* currentNode = head;
  while (currentNode->next) {
    currentNode = currentNode->next;
  }
  dll* newNode = (dll*)malloc(sizeof(dll));
  newNode->val = strdup(str);
  newNode->next = NULL;
  newNode->prev = currentNode;
  currentNode->next = newNode;
}

void dllPrepend(dll* head, const char* str) {
  dll* currentNode = head;
  while (currentNode->prev) {
    currentNode = currentNode->prev;
  }
  dll* newNode = (dll*)malloc(sizeof(dll));
  newNode->val = strdup(str);
  newNode->next = currentNode;
  newNode->prev = NULL;
  currentNode->prev = newNode;
}

void dllInsertAfter(dll* head, dll* currentNode, const char* strToInsert) {
  if (currentNode->next) {
    dll* temp = currentNode->next;
    dll* newNode = (dll*)malloc(sizeof(dll));
    newNode->val = strdup(strToInsert);
    newNode->next = temp;
    newNode->prev = currentNode;
    currentNode->next = newNode;
    temp->prev = newNode;
  } else {
    dll* newNode = (dll*)malloc(sizeof(dll));
    newNode->val = strdup(strToInsert);
    newNode->next = NULL;
    newNode->prev = currentNode;
    currentNode->next = newNode;
  }
}

void dllInsertBefore(dll* head, dll* currentNode, const char* strToInsert) {
  if (currentNode->prev) {
    dll* temp = currentNode->prev;
    dll* newNode = (dll*)malloc(sizeof(dll));
    newNode->val = strdup(strToInsert);
    newNode->prev = temp;
    newNode->next = currentNode;
    currentNode->prev = newNode;
    temp->next = newNode;
  } else {
    dll* newNode = (dll*)malloc(sizeof(dll));
    newNode->val = strdup(strToInsert);
    newNode->prev = NULL;
    newNode->next = currentNode;
    currentNode->prev = newNode;
  }
}

dll* dllFind(dll* head, const char* str) {
  dll* currentNode = head;
  while (currentNode->next) {
    if (strcmp(currentNode->val, str) == 0) {
      return currentNode;
    } else {
      currentNode = currentNode->next;
    }
  }
  // if head is not the left-most node, we search backwards
  currentNode = head;
  while (currentNode->prev) {
    if (strcmp(currentNode->val, str) == 0) {
      return currentNode;
    } else {
      currentNode = currentNode->prev;
    }
  }
  return NULL;
}

int dllLength(dll* head) {
  int length = 1;
  dll* currentNode = head;
  while (currentNode->next) {
    length += 1;
    currentNode = currentNode->next;
  }
  currentNode = head;
  while (currentNode->prev) {
    length += 1;
    currentNode = currentNode->prev;
  }
  return length;
}

void dllDeleteNode(dll* node) {
  if (node->prev && node->next) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node->val);
    free(node);
  } 
  else if (node->prev) {
    node->prev->next = NULL;
    free(node->val);
    free(node);
  } 
  else if (node->next) {
    node->next->prev = NULL;
    free(node->val);
    free(node);
  } else {
    free(node->val);
    free(node);
  }
}

void dllPrint(dll* head) {
  printf("START\n");
  dll* currentNode = head;
  while (currentNode->prev) {
    currentNode = currentNode->prev;
  }
  printf("\t↑\t\n");
  while (currentNode->next) {
    printf("\t%s\t\n\t↑↓\t\n", currentNode->val);
    currentNode = currentNode->next;
  }
  printf("\t%s\t\n\t↓\t\n", currentNode->val);
  printf("END\n");
}

dll* dllCreate(const char* headStr, int lenAppend, int lenPrepend, char** appendLst, char** prependLst) {
  dll* head = (dll*)malloc(sizeof(dll));
  head->val = strdup(headStr);
  head->next = NULL;
  head->prev = NULL;
  for (int i = 0; i < lenAppend; i++) {
    dllAppend(head, appendLst[i]);
  }
  for (int j = lenPrepend - 1; j > -1; j--) {
    dllPrepend(head, prependLst[j]);
  }
  return head;
}

void dllDestroy(dll* head) {
  while (head->next) {
    dllDeleteNode(head->next);
  }
  while (head->prev) {
    dllDeleteNode(head->prev);
  }
  dllDeleteNode(head);
}
