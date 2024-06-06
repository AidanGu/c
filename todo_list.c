#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ll_text {
  char *text;
  struct ll_text *next;
} ll_text;

ll_text *add_to_front(char *text, ll_text *list) {
  ll_text *front = NULL;
  front = calloc(1, sizeof(ll_text));
  front->text = strdup(text);
  front->next = list;
  return front;
}

int main(void) {
  // give me a pointer to an ll_text. this is declaring a variable.
  ll_text *list = NULL;

  list = calloc(1, sizeof(ll_text));
  list->text = strdup("wash the dog");
  //  [ ("wash the dog") ]

  list->next = calloc(1, sizeof(ll_text));
  list->next->text = strdup("do the midterm");
  //  [ ("wash the dog"), ("do the midterm") ]

  list = add_to_front("drink more coffee", list);
  //  [("drink more coffee") ("wash the dog"), ("do the midterm") ]

  ll_text *here = list;
  while(here) {
    printf("TODO: %s\n", here->text);
    here = here->next;
  }

  return 0;
}
