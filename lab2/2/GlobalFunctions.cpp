#include "GlobalFunctions.h"
#include <iostream>
int compareEnglish(Student* s1,  Student* s2) {
	float eng1 = s1->getEnglish();
	float eng2 = s2->getEnglish();
	if (eng1 == eng2) return 0;
	if (eng1 > eng2) return 1;
	if (eng1 < eng2) return -1;
}
int compareMathematics( Student* s1,  Student* s2) {
	float math1 = s1->getMathsematics();
	float math2 = s2->getMathsematics();
	if (math1 == math2) return 0;
	if (math1 > math2) return 1;
	if (math1 < math2) return -1;
}
int compareHistory( Student* s1,  Student* s2) {
	float history1 = s1->getMathsematics();
	float history2 = s2->getMathsematics();
	if (history1 == history2) return 0;
	if (history1 > history2) return 1;
	if (history1 < history2) return -1;
}
int compareAverage( Student* s1,  Student* s2) {
	float average = s1->getAverage();
	float average2 = s2->getAverage();
	if (average == average2) return 0;
	if (average > average2) return 1;
	if (average < average2) return -1;
}
int compareName( Student* s1,  Student* s2) {
	int result = strcmp(s1->getName(), s2->getName());
	return result;
}
