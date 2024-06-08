#include <stdio.h>

int add(int a, int b) {
  return a + b; 
}

int other_combine(int a, int b) {
  return a * 3 - b;
}

int combine_numbers(int (*combiner)(int, int), int a, int b) {
  int answer = combiner(a, b);
  return answer;
}

int main(void) {
  int tool_number = combine_numbers(add, 46, 2);
  printf("here's the answer: %d\n", tool_number);

  int other_number = combine_numbers(other_combine, 46, 2);
  printf("here's the answer: %d\n", other_number);

  int (*funk_pointer)(int, int) = other_combine;
  printf("here's the function pointer: %p\n", funk_pointer);

  return 0;
}
