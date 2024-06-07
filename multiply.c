#include <stdio.h>
#include <stdlib.h>

unsigned int multiply(unsigned int a, unsigned int b) {
  if (b == 0) {
    return 0;
  } else {
    return a + multiply(a, b - 1);
  }
}

// TODO(alexr): implement Newton's method here.
