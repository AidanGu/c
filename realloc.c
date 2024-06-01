#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int *my_fav_numbers = calloc(5, sizeof(int));

  printf("array is at: %p\n", (void*)my_fav_numbers);

  my_fav_numbers[0] = 13;
  my_fav_numbers[1] = 78;
  my_fav_numbers[2] = 105;
  my_fav_numbers[3] = 23;
  my_fav_numbers[4] = 97;


  my_fav_numbers = realloc(my_fav_numbers, 10 * sizeof(int));

  printf("number 0: %d\n", my_fav_numbers[0]);
  printf("array is now at: %p\n", (void*)my_fav_numbers);

  return 0;
}
