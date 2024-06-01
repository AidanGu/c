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

    // today y is a CONSONANT.
    // count a, e, i, o, u
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
        || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      num_vowels++;
    } else {
      other_characters++;
    }

  }
  printf("I found this many vowels: %d\n", num_vowels);
  printf("I found this many other characters: %d\n", other_characters);

  return 0;
}
