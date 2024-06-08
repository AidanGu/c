#include <stdio.h>

int better_strcmp(char *a, char *b) {
  int i = 0;
  for (i = 0; a[i] && b[i]; i++) {
    if (a[i] - b[i]) {
      return (a[i] - b[i]);
    }
  }
  if (!a[i] && b[i]) {
    return 1;
  } else if(a[i] && !b[i]) {
    return -1;
  }

  return 0;
}

int main(void) {

  printf("%d\n", better_strcmp("Jimmy", "Bimmy"));
  printf("%d\n", better_strcmp("Bimmy", "Jimmy"));

  printf("%d\n", better_strcmp("Bimmy Johnson", "Bimmy"));
  printf("%d\n", better_strcmp("Bimmy", "Bimmy Johnson"));

  return 0;
}
