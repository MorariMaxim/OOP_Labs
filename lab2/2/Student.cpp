#include "Student.h"

int Student::getEnglish() {
	return english;
}
int Student::getHistory() {
	return history;
}

int Student::getMathsematics() {
	return mathematics;
}
void Student::setMathsematics(int grade) {
	mathematics = grade;
}
void Student::setEnglish(int grade) {
	english = grade;
}
void Student::setHistory(int grade) {
	history = grade;
}

char* Student::getName() {
	return name;
}

void Student::setName(const char* toset) {
	if (name != nullptr) delete name;
	name = (char*)toset;
	
}
float Student::getAverage() {
	return (float)(getMathsematics() + getEnglish() + getHistory()) / 3;
}