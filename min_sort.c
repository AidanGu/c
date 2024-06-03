#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void min_sort(int *arr, int size, int (*comparison)(int, int)) {
  if (size <= 1) {
    return;
  }
  int earliest_so_far = arr[0];
  int earliest_index = 0;
  for (int i = 0; i < size; i++) {
    int result = comparison(arr[i], earliest_so_far);
    if (result < 0) {
      earliest_so_far = arr[i];
      earliest_index = i;
    }
  }
  int tmp = arr[0];
  arr[0] = earliest_so_far;
  arr[earliest_index] = tmp;
  min_sort(arr + 1, size - 1, comparison);
}

int compare_increasing(int left, int right) {
  return left - right;
}

int compare_increasing_abs(int left, int right) {
  return abs(left) - abs(right);
}

int main(void) {
  const int ARR_SIZE = 10;
  int numbers[] = {7, 3, 18, 201, 42, 67, 8, 1, -4, 100};

  min_sort(numbers, ARR_SIZE, compare_increasing_abs);
  for(int i=0; i < ARR_SIZE; i++) {
    printf("number: %d\n", numbers[i]);
  }

  return 0;
}
