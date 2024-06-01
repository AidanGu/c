#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // do getchar over and over until we get to the end of the input.
  //

  int num_lines = 0;
  int num_es = 0;
  while(1) {
    int c = getchar();

    if (c == EOF) {
      break;
    }

    if (c == '\n') {
      num_lines += 1;
    }

    if (c == 'e') {
      num_es++;
    } else {
      putchar(c);
    }

  }
  printf("I found this many lines: %d\n", num_lines);
  printf("I found this many letter e: %d\n", num_es);

  return 0;
}
