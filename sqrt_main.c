#include <stdio.h>

#include "sqrt_lib.h"

int main(void) {

  double number = 64.0;
  double answer = sqrt_approx(number);

  printf("the square root of %f is %f\n", number, answer);
  return 0;
}
