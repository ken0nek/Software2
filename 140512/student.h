#include <strings.h>

class Student {
private:
	char name[32];
	int grade;

public:
	Student(const char* _name) {
		strcpy(name, _name);
		grade = 0;
	}
	~Student() {
	}

	void SetGrade(int _grade) {
		grade = _grade;
	}

	int GetGrade() {
		return grade;
	}

	char* GetName() {
		return name;
	}
};