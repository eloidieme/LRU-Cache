#ifndef __DLL_H__
#define __DLL_H__

typedef struct dll 
{
  char* val;
  struct dll* next;
  struct dll* prev;
} dll;

void dllAppend(dll* head, const char* str);
void dllPrepend(dll* head, const char* str);
void dllInsertAfter(dll* head, dll* currentNode, const char* strToInsert);
void dllInsertBefore(dll* head, dll* currentNode, const char* strToInsert); 
dll* dllFind(dll* head, const char* str);
int dllLength(dll* head);
void dllDeleteNode(dll* node);
void dllPrint(dll* head);
dll* dllCreate(const char* headStr, int lenAppend, int lenPrepend, char** appendLst, char** prependLst);
void dllDestroy(dll* head);

#endif
