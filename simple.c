#include <stdio.h>
#include <stdlib.h>

// Takes two numbers and adds them to seven.
int seven_plus_numbers(int num1, int num2) {
  int output = 7 + num1 + num2;

  num1 = 0;

  return output;
}

int main(int argc, char *argv[]) {
  int result = 0;

  int ten = 10;
  int one_oh_three = 103;
  result = seven_plus_numbers(ten, one_oh_three);

  printf("here is the results of calling seven_plus_numbers: %d\n", result);

  return 0;
}
