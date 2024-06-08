#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ll_int {
  int value;
  struct ll_int *next;
} ll_int;


bool value_is_present(int value, ll_int *list) {
  if (list == NULL) {
    return false;
  }
  if (list->value == value) {
    return true;
  }
  return value_is_present(value, ll_list->next);
}


int main(void) {

  return 0;
}
