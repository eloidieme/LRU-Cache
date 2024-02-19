#ifndef __DLL_H__
#define __DLL_H__

typedef struct dll 
{
  char* val;
  struct dll* next;
  struct dll* prev;
} dll;

void append(dll* head, char* str);
void prepend(dll* head, char* str);
dll* find(dll* head, char* str);
int delete(dll* node);
dll* create(char* head_str, int len_append, int len_prepend, char** append_lst, char** prepend_lst);

#endif