#include <stdio.h>
#include <stdlib.h>

#include "multiply.h"

int main(void) {

  unsigned int alan = 4;
  unsigned int beth = 10;

  unsigned int result = multiply(alan, beth);

  printf("result of 4 times 10: %d\n", result);

  return 0;
}
