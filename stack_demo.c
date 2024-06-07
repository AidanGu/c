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

linkedlist_int* push(int value, linkedlist_int* existing) {
  linkedlist_int* out;

  out = new_node(value);
  out->next = existing;

  return out;
}

// pop operation
int pop(linkedlist_int **stack) {
  if (*stack == NULL) {
    // shoot it's empty
    printf("you tried to pop an empty stack\n");
    return -1;
  }

  int output = (*stack)->value;

  linkedlist_int* free_this = (*stack);
  *stack = (*stack)->next;

  free(free_this);
  return output;
}

void print_linked_list(linkedlist_int* list) {
  if (!list) {
    return;
  }
  printf("here's a value: %d\n", list->value);
  print_linked_list(list->next);
}


int main(void) {
  linkedlist_int* stack = NULL;

  stack = push(70, stack);

  int popped = pop(&stack);
  printf("number: %d\n", popped);
  printf("stack should be null: %p\n", stack);

  return 0;
}
