#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  char grade_hw_1;
} Student;


void string_copy(char *src, char *dest) {
  for(int i=0; src[i]; i++) {
    dest[i] = src[i];
  }
}

Student make_student(char *name, char grade_hw_1) {
  Student out;
  out.name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
  string_copy(name, out.name);
  out.grade_hw_1 = grade_hw_1;

  return out;
}

void print_student(Student student) {
  printf("student: %s got grade %c\n", student.name, student.grade_hw_1);
}

int main(void) {
  Student sally = make_student("Sally Soccermill", 'A');
  print_student(sally);

  Student* many_students = calloc(sizeof(Student), 10);

  many_students[0].name = strdup("Bimmy");
  many_students[0].grade_hw_1 = 'Y';

  print_student(many_students[0]);

  return 0;
}
