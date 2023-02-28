#include <iostream>
#include "GlobalFunctions.h"
#include <algorithm>

bool sortStudents(Student s1,Student s2) {
    return s1.getAverage() > s2.getAverage();
}

int main()
{
    time_t current_time = time(NULL);
    srand((unsigned)time(NULL));
    Student students[6];
    for (int i = 0; i < 6; i++) {
        float randnum = rand() % 10;
        if (randnum < 5) randnum += 6;
        students[i].setEnglish(randnum);        
        students[i].setHistory(randnum);
        randnum = rand() % 10;
        if (randnum < 5) randnum += 6;
        students[i].setMathsematics(randnum);
        randnum = rand() % 10;
        if (randnum < 5) randnum += 6;
    }
    students[0].setName("Ivan");
    students[1].setName("Victor");
    students[2].setName("Xenia");
    students[3].setName("Aida");
    students[4].setName("Diana");
    students[5].setName("Vitalie");

    std::sort(students, students + 6, sortStudents);
    for (int i = 0; i < 6; i++) {
        printf("%s, average= %f\n", students[i].getName(), students[i].getAverage());
    }
}
