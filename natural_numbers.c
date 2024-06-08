#include <stdio.h>

int sum_natural_numbers(int k) {
  if (k == 0) {
    return 0;
  }
  printf("currently adding %d\n", k);
  int output = k + sum_natural_numbers(k - 1);
  return output;
}

int main(void) {

  int total = sum_natural_numbers(5);
  printf("total: %d\n", total);

  return 0;
}
