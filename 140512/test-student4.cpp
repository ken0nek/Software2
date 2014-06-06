#include <stdio.h>
#include <string.h>
#include "labmember4.h"
#include "student4.h"
#include "professor4.h"
#include "lab4.h"

int main(int argc, char const *argv[])
{
	Lab jsk;
	Lab jfk;
	Professor *p1 = new Professor();
	Student *s1 = new Student();
	Professor *p2 = new Professor();
	Student *s2 = new Student();

	p1->SetName("Okada");
	p2->SetName("John");
	s1->SetName("Tominaga");
	s2->SetName("Tommy");

	p1->SetRoom(123);
	s1->SetGrade(3);
	p2->SetRoom(1963);
	s2->SetGrade(12);

	jsk.AddMember(p1);
	jsk.AddMember(s1);
	jfk.AddMember(p2);
	jfk.AddMember(s2);

	printf("jsk\n");
	jsk.PrintMember();
	printf("jfk\n");
	jfk.PrintMember();

	delete p1;
	delete s1;
	delete p2;
	delete s2;

	return 0;
}