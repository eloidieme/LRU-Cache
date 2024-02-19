#include <stdlib.h>
#include <string.h>

#include "./dll.h"

void append(dll* head, char* str) {
  dll* current_node = head;
  while (current_node->next) {
    current_node = current_node->next;
  }
  dll* new_node = malloc(sizeof(dll));
  new_node->val = str;
  new_node->next = NULL;
  new_node->prev = current_node;
  current_node->next = new_node;
}

void prepend(dll* head, char* str) {
  dll* current_node = head;
  while (current_node->prev) {
    current_node = current_node->prev;
  }
  dll* new_node = malloc(sizeof(dll));
  new_node->val = str;
  new_node->next = current_node;
  new_node->prev = NULL;
  current_node->prev = new_node;
}

dll* find(dll* head, char* str) {
  // try to find a symmetric solution for searching
  dll* current_node = head;
  while (current_node->next) {
    if (strcmp(current_node->val, str) == 0) {
      return current_node;
    } else {
      current_node = current_node->next;
    }
  dll* current_node = head;
  while (current_node->prev) {
      if (strcmp(current_node->val, str) == 0) {
        return current_node;
      } else {
        current_node = current_node->prev;
      }
    }
  }
  return NULL;
}

int delete(dll* node) {
  if (node->prev && node->next) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    free(node);
    return 0;
  } 
  if (node->prev) {
    node->prev->next = NULL;
    free(node);
    return 0;
  } 
  if (node->next) {
    node->next->prev = NULL;
    free(node);
    return 0;
  }
  return -1;
}

dll* create(char* head_str, int len_append, int len_prepend, char** append_lst, char** prepend_lst) {
  dll* head = malloc(sizeof(dll));
  head->val = head_str;
  head->next = NULL;
  head->prev = NULL;
  for (int i = 0; i < len_append; i++) {
    append(head, append_lst[i]);
  }
  for (int j = 0; j < len_prepend; j++) {
    prepend(head, prepend_lst[j]);
  }
  return head;
}

void destroy(dll* head) {

}
