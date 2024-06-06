#include <stdio.h>
#include <stdlib.h>

typedef struct linkedlist_int {
  int value;
  struct linkedlist_int *next;
} linkedlist_int;


linkedlist_int* new_node(int value) {
  linkedlist_int* out;

  out = (linkedlist_int *) malloc(sizeof(linkedlist_int));
  out->value = value;
  out->next = NULL;

  return out;
}

// historical note, this is a cons
linkedlist_int* add_to_front(int value, linkedlist_int* existing) {
  linkedlist_int* out;

  out = new_node(value);
  out->next = existing;

  return out;
}

void print_linked_list(linkedlist_int* list) {
  if (!list) {
    return;
  }
  printf("here's a value: %d\n", list->value);
  print_linked_list(list->next);
}

void free_linked_list(linkedlist_int* list) {
  if (!list) {
    return;
  }
  free_linked_list(list->next);
  free(list);
}


int main(void) {
  linkedlist_int* beginning;

  beginning = new_node(100);

  beginning = add_to_front(70, beginning);
  beginning = add_to_front(29, beginning);
  beginning = add_to_front(903, beginning);
  beginning = add_to_front(4, beginning);

  print_linked_list(beginning);

  free_linked_list(beginning);

  char *bytes_to_not_leak = calloc(sizeof(char), 1024 * 1024);
  free(bytes_to_not_leak);
  bytes_to_not_leak = NULL;

  return 0;
}
