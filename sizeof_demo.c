#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void) {

  printf("how big is an int? %lu\n", sizeof(int));

  printf("how big is a long? %lu\n", sizeof(long));

  printf("how big is a long long? %lu\n", sizeof(long long));

  printf("how big is a float? %lu\n", sizeof(float));

  printf("how big is a double? %lu\n", sizeof(double));

  printf("how big is this nonsense? %lu\n", sizeof(10 - 4));


  return 0;
}
