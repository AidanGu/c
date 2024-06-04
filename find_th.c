#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {

  int c;
  int prev_char = 0;
  int probably_english = 0;

  while (true) {
    c = getchar();
    if (c == EOF) {
      break;
    }

    if (c == 'h' && prev_char == 't') {
      printf("found one! it is probably English.\n");
      probably_english = true;
    }

    prev_char = c;
  }

  printf("%d\n", probably_english);

  return 0;
}
