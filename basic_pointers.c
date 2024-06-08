#include <stdio.h>

int main(void) {

  int x = 17;

  int *p = NULL;

  p = &x;

  printf("here's the memory location of x: %p\n", &x);
  printf("here's the memory location p: %p\n", p);

  printf("here's the value at location p: %d\n", *p);

  printf("here's the memory location *of* p: %p\n", &p);

  // let's set the integer using the pointer
  *p = 97;
  printf("here's the value at location p now: %d\n", *p);
  printf("here's the value of x: %d\n", x);

  // we're done with p now, set it to NULL.
  p = NULL;
  printf("here's the memory location p: %p\n", p);

  // set it!!
  *p = 42;


  return 0;
}
