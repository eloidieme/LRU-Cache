#ifndef __DLL_H__
#define __DLL_H__

typedef struct dll 
{
  char* val;
  struct dll* next;
  struct dll* prev;
} dll;

void append(dll* head, const char* str);
void prepend(dll* head, const char* str);
void insertAfter(dll* head, dll* currentNode, const char* strToInsert);
void insertBefore(dll* head, dll* currentNode, const char* strToInsert); 
dll* find(dll* head, const char* str);
void deleteNode(dll* node);
void printDll(dll* head);
dll* create(const char* headStr, int lenAppend, int lenPrepend, char** appendLst, char** prependLst);
void destroy(dll* head);

#endif
