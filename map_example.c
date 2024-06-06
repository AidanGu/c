#include <stdio.h>

int square(int x) {
  return x * x;
}

// pass a NULL pointer for output if you do not wish to write into an output
void map_array(int (* function)(int), int *arr, int size, int *output) {
  for(int i=0; i < size; i++) {
    int result = function(arr[i]);
    if (output != NULL)  {
      output[i] = result;
    }
  }
}

int print_thing(int x) {
  printf("here is a thing in the array: %d\n", x);
  return 0;
}

void print_array(int *arr, int size) {
  map_array(print_thing, arr, size, NULL);
}


int double_int(int x) {
  return x * 2;
}

void double_array(int *arr, int size, int *output) {
  map_array(double_int, arr, size, output);
}


int main(void) {
  const int ARR_SIZE = 10;
  int numbers[] = {7, 3, 18, 201, 42, 67, 8, 1, -4, 100};
  int output_array[10];

  double_array(numbers, ARR_SIZE, output_array);

  printf("initial array\n");
  print_array(numbers, ARR_SIZE);

  printf("output array\n");
  print_array(output_array, ARR_SIZE);

  printf("and now! we square.\n");
  map_array(square, numbers, ARR_SIZE, output_array);

  printf("output array after squaring\n");
  print_array(output_array, ARR_SIZE);

  return 0;
}
