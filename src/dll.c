#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./dll.h"

void append(dll* head, const char* str) {
  dll* current_node = head;
  while (current_node->next) {
    current_node = current_node->next;
  }
  dll* new_node = (dll*)malloc(sizeof(dll));
  new_node->val = strdup(str);
  new_node->next = NULL;
  new_node->prev = current_node;
  current_node->next = new_node;
}

void prepend(dll* head, const char* str) {
  dll* current_node = head;
  while (current_node->prev) {
    current_node = current_node->prev;
  }
  dll* new_node = (dll*)malloc(sizeof(dll));
  new_node->val = strdup(str);
  new_node->next = current_node;
  new_node->prev = NULL;
  current_node->prev = new_node;
}

dll* find(dll* head, const char* str) {
  dll* current_node = head;
  while (current_node->next) {
    if (strcmp(current_node->val, str) == 0) {
      return current_node;
    } else {
      current_node = current_node->next;
    }
  // if head is not the left-most node, we search backwards
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

void delete(dll* node) {
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

void print_dll(dll* head) {
  dll* current_node = head;
  while (current_node->prev) {
    current_node = current_node->prev;
  }
  printf("\t↑\t\n");
  while (current_node->next) {
    printf("\t%s\t\n\t↑↓\t\n", current_node->val);
    current_node = current_node->next;
  }
  printf("\t%s\t\n\t↓\t\n", current_node->val);
}

dll* create(const char* head_str, int len_append, int len_prepend, char** append_lst, char** prepend_lst) {
  dll* head = (dll*)malloc(sizeof(dll));
  head->val = strdup(head_str);
  head->next = NULL;
  head->prev = NULL;
  for (int i = 0; i < len_append; i++) {
    append(head, append_lst[i]);
  }
  for (int j = len_prepend - 1; j > -1; j--) {
    prepend(head, prepend_lst[j]);
  }
  return head;
}

void destroy(dll* head) {
  while (head->next) {
    delete(head->next);
  }
  while (head->prev) {
    delete(head->prev);
  }
  delete(head);
}
