#include <stdio.h>

void division_with_remainder(int numerator, int denominator,
    int *quotient, int *remainder) {
  int result1 = numerator / denominator;
  int result2 = numerator % denominator;

  *quotient = result1;
  *remainder = result2;
}

int main(void) {
  int quotient;
  int remainder;

  division_with_remainder(107, 10, &quotient, &remainder);

  printf("%d, %d\n", quotient, remainder);

  return 0;
}
