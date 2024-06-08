#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // start at 0 fahrenheit
  // go up to 300 fahrenheit
  // conversion looks like C = (F - 32) * 5/9

  for (float fahrenheit = 0.0; fahrenheit < 300; fahrenheit += 1) {
    // do some math
    float celsius = 0;
    celsius = (fahrenheit - 32.0) * 5 / 9;
    // print the answer
    printf("%0.1f fahrenheit is %0.1f celsius\n", fahrenheit, celsius);
  }

  return 0;
}
