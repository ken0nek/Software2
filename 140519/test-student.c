#include <stdio.h>

typedef struct {
    char *name;
    int grade;
}STUDENT;

int main(int argc, char *argv[]) {
    STUDENT s1, s2;
    s1.name = "suzuki";
    s2.name = "yamada";

    s1.grade = 3;
    s2.grade = 4;

    printf("student name = %s (%d)\n", s1.name, s1.grade);
    printf("student name = %s (%d)\n", s2.name, s2.grade);

    return 0;
}
