#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct ll_todo {
  char *message;
  struct ll_todo *next;
} ll_todo;


ll_todo* new_node(char *message) {
  ll_todo* out;

  out = (ll_todo *) malloc(sizeof(ll_todo));
  out->message = strdup(message);
  out->next = NULL;

  return out;
}

ll_todo* push(char *message, ll_todo* existing) {
  ll_todo* out;

  out = new_node(message);
  out->next = existing;

  return out;
}

// pop operation
char *pop(ll_todo **stack) {
  if (*stack == NULL) {
    // shoot it's empty
    printf("you tried to pop an empty stack\n");
    return NULL;
  }

  char* output = (*stack)->message;
  ll_todo* free_this = (*stack);
  *stack = (*stack)->next;

  free(free_this);
  return output;
}


int main(void) {
  ll_todo* stack = NULL;

  char buf[80];
  printf("what is your quest?\n");
  fgets(buf, 80, stdin);
  stack = push(buf, stack);

  while(stack) {
    printf("current problem to solve: %s\n", stack->message);

    while(true) {
      printf("can you do that right now? y/n: ");
      fgets(buf, 80, stdin);
      if (buf[0] != 'y' && buf[0] != 'n') {
        continue;
      } else {
        break;
      }
    }

    if (buf[0] == 'y') {
      char *message = pop(&stack);
      printf("task: %s\n", message);
      printf("successful: you really did that\n");
      free(message);
    } else if(buf[0] == 'n') {
      printf("what else do you need to do to do that? ");
      fgets(buf, 80, stdin);
      stack = push(buf, stack);
    }
  }
  printf("CONGRATULATINOS.\n");

  return 0;
}

