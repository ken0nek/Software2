#include <stdio.h>
#include <string.h>
#include "student.h"

int main(int argc, char const *argv[])
{
	Student s1("Tominaga");
	Student s2("Konishi");

	s1.SetGrade(3);
	s2.SetGrade(2);

	printf("student name = %s (%d)\n", s1.GetName(), s1.GetGrade());
	printf("student name = %s (%d)\n", s2.GetName(), s2.GetGrade());

	s1.Promotion();
	s2.Promotion();

	printf("student name = %s (%d) next year\n", s1.GetName(), s1.GetGrade());
	printf("student name = %s (%d) next year\n", s2.GetName(), s2.GetGrade());

	return 0;
}