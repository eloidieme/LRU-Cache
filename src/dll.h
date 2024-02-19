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
dll* find(dll* head, const char* str);
void delete(dll* node);
void print_dll(dll* head);
dll* create(const char* head_str, int len_append, int len_prepend, char** append_lst, char** prepend_lst);
void destroy(dll* head);

#endif