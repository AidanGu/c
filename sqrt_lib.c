#include <stdbool.h>

#include "sqrt_lib.h"

double my_abs(double x) {
  if (x < 0) {
    return -1 * x;
  } else {
    return x;
  }
}

double sqrt_approx(double x) {
  // initial guess is x/2
  // next guess is the average of current guess and (x / current)
  // stop the iteration when difference between current and x/current is less
  // than epsilon.
  
  double current = x / 2;
  while(true) {
    if (my_abs(current - (x / current)) < 0.0001) {
      break;
    }
    current = (current + (x / current)) / 2;
  }
  return current;
}
