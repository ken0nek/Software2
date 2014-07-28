#-*- coding:utf-8 -*-

class Student:
    def __init__(self, name):
        self.name = name
    def setGrade(self, grade):
        self.grade = grade


def main():
    s1 = Student("yamada")
    s2 = Student("suzuki")

    s1.setGrade(1)
    s2.setGrade(2)

    format = "student name = {0} ({1})"
    print format.format(s1.name, s1.grade)
    print format.format(s2.name, s2.grade)

main()
