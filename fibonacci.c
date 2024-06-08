#include <stdio.h>

long long fib_recursive(int k) {
  if (k == 0) {
    return 0;
  } else if (k == 1) {
    return 1;
  } else {
    return fib_recursive(k - 1) + fib_recursive(k - 2);
  }
}

long long fib_memoized(int k, long long *lookup, int table_length) {
  if (k == 0) {
    return 0;
  } else if (k == 1) {
    return 1;
  } else {
    if ((k < table_length) && lookup[k]) {
      return lookup[k];
    }
    long long answer = (fib_memoized(k - 1, lookup, table_length)
                        + fib_memoized(k - 2, lookup, table_length));
    lookup[k] = answer;
    return answer;
  }
}

long long fib_loop(int k) {
  long long prevprev = 0;
  long long prev = 1;
  long long output;
  if (k == 0) {
    return 0;
  } else if (k == 1) {
    return 1;
  }
  for (int i = 2; i <= k; i++) {
    output = prevprev + prev;

    prevprev = prev;
    prev = output;
  }
  return output;
}

int main(void) {

  long long lookup_table[100] = {0};

  for (int k=0; k < 100; k++) {
    printf("the %dth fib is: %lld\n", k, fib_loop(k));
  }

  return 0;
}
