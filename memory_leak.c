#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
  size_t memory_size = (1024 * 1024);
  void *some_memory = NULL;

  while(true) {
    some_memory = malloc(memory_size);
    printf("here's the memory address: %p\n", some_memory);

    if (!some_memory) {
      printf("I ran out.\n");
      break;
    }
    memory_size *= 2;
    getchar();
  }

  return 0;
}
