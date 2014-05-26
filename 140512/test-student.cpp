#include <stdio.h>
#include "student.h"

int main(int argc, char const *argv[])
{
	Student s1("tominaga");
	Student s2("konishi");

	s1.SetGrade(3);
	s2.SetGrade(2);

	printf("student name = %s (%d)\n", s1.GetName(), s1.GetGrade());
	printf("student name = %s (%d)\n", s2.GetName(), s2.GetGrade());

	return 0;
}