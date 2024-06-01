#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  // do getchar over and over until we get to the end of the input.

  int num_vowels = 0;
  int other_characters = 0;
  while(1) {
    int c = getchar();

    if (c == EOF) {
      break;
    }

    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        num_vowels++;
        break;
      default:
        other_characters++;
        break;
    }

  }
  printf("I found this many vowels: %d\n", num_vowels);
  printf("I found this many other characters: %d\n", other_characters);

  return 0;
}
