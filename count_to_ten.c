#include <stdio.h>

int main(int argc, char *argv[]) {

  for (int i=1; i <= 10; i++) {
    printf("%d\n", i);
  }

  int number = 1;
  while (number <= 10) {
    printf("%d\n", number);
    number += 1;
  }

  int other_number = 1;
  do {
    printf("%d\n", other_number);
    other_number += 1;
  } while(other_number <= 10);

}
