/* test-student4.cpp */
#include <stdio.h>
#include <string.h>
#include "labmember4.h"
#include "student4.h"
#include "professor4.h"
#include "lab4.h"

int main(int argc, char** argv) {
    Lab jsk;
    Professor *p1 = new Professor();
    Student *s1 = new Student();
    Professor *p2 = new Professor();
    Student *s2 = new Student();

    p1->SetName((char*)"yamada");
    s1->SetName((char*)"suzuki");
    p1->SetRoom(123);
    s1->SetGrade(4);
    jsk.AddMember(p1);
    jsk.AddMember(s1);

    p2->SetName((char*)"tanaka");
    s2->SetName((char*)"watanabe");
    p2->SetRoom(234);
    s2->SetGrade(5);
    jsk.AddMember(p2);
    jsk.AddMember(s2);

    jsk.PrintMember();

    delete p1;
    delete s1;
    delete p2;
    delete s2;
    return 0;
}
