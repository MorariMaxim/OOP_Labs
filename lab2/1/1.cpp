#include <iostream>
#include "NumberList.h"

int main()
{
    NumberList nl;
    nl.Init();
    for (int i = 0; i < 6; i++) {
        nl.Add(rand());
    }
    for (int i = 0; i < 6; i++) {
        nl.Add(rand());
    }
    nl.Print();
    nl.Sort();
    nl.Print();    
} 
