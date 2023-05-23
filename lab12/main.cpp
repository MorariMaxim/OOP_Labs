#include <iostream>
#include "clase.h"

using namespace std;
int main()
{
    
    Agenda a;
    a.adauga(new Prieten());
    a.adauga(new Coleg());
    a.adauga(new Cunoscut());

    auto p = a.prieteni();

    cout << p.size();
}