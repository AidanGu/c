#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void print_bits(unsigned char c) {

  // let's use bitwise and
  for (int shiftsize = 7; shiftsize >= 0; shiftsize--) {
    printf("%d", (0 != (c & (1 << shiftsize))));

    // printf("%d", (c & (1 << shiftsize)));
  }
  printf("\n");
}

typedef uint64_t set;

set add_item(set current, int item) {
  current = current | (1 << item);
  return current;
}

set remove_item(set current, int item) {
  current = current & ~(1 << item);
  return current;
}

bool exists(set current, int item) {
  return (0 != (current & (1 << item)));
}


int main(void) {

  uint64_t number = 0;
  print_bits(42);
  printf("%lu\n", number);

  printf("now we're talking about sets.\n");
  set myset = 0;
  myset = add_item(myset, 2);
  printf("is item 2 in there? %d\n", exists(myset, 2));

  myset = remove_item(myset, 2);
  printf("is item 2 in there? %d\n", exists(myset, 2));
  printf("is item 4 in there? %d\n", exists(myset, 4));

  set fluffy = 0;
  fluffy = add_item(fluffy, 4);
  fluffy = add_item(fluffy, 7);
  fluffy = add_item(fluffy, 38);

  set delicious = 0;
  delicious = add_item(delicious, 10);
  delicious = add_item(delicious, 60);
  delicious = add_item(delicious, 7);

  printf("%lu\n", fluffy & delicious);

  return 0;
}
