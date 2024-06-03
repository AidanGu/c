#include <stdio.h>

#include "sum_positive_integer.h"

int sum_positive_digits_iterative(int n) {
  int total = 0;
  while (n > 0) {
    int digit = n % 10;
    total = total + digit;
    n = n / 10;
  }
  return total;
}

int sum_positive_digits(int n) {
  if (n == 0) {
    return 0;
  }

  int smaller = n / 10;
  return (n % 10) + sum_positive_digits(smaller);
}

int main(int argc, char *argv[]) {

  int num = 27;
  int result = sum_positive_digits(num);
  printf("this should return 9: %d\n", result);

  num = 127;
  result = sum_positive_digits(num);
  printf("this should return 10: %d\n", result);

  num = 20127;
  result = sum_positive_digits(num);
  printf("this should return 12: %d\n", result);

  return 0;
}
