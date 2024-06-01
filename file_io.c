#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void typos(char *buf) {
  char prev;

  for (int i = 1; i < (int)strlen(buf) - 1; i++) {
    int num = rand();
    if ((num % 10) == 0) {
      prev = buf[i - 1];
      buf[i - 1] = buf[i];
      buf[i] = prev;
    }
  }
}

int main(void) {
  FILE *infile;
  FILE *outfile;

  srand(time(NULL));
  char buffer[1024];
  infile = fopen("story.txt", "r");
  outfile = fopen("story_better.txt", "w");

  while (fgets(buffer, 1024, infile) != NULL) {
    printf("I got this line: %s", buffer);
    typos(buffer);
    printf("new version: %s", buffer);

    fprintf(outfile, "%s", buffer);
  }

  fclose(infile);
  fclose(outfile);

  return 0;
}
