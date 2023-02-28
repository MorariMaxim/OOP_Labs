#include "Student.h"

float Student::getEnglish() {
	return english;
}
float Student::getHistory() {
	return history;
}
float Student::getMathsematics() {
	return mathematics;
}
void Student::setMathsematics(float grade) {
	mathematics = grade;
}
void Student::setEnglish(float grade) {
	english = grade;
}
void Student::setHistory(float grade) {
	history = grade;
}
char* Student::getName() {
	return name;
}
void Student::setName(const char* toset) {
	if (name != nullptr) delete[] name;
	name = (char*)toset;	
}
float Student::getAverage() {
	return (float)(getMathsematics() + getEnglish() + getHistory()) / 3;
}
