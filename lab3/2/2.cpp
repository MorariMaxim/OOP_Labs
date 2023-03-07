#include <iostream>
#include "Canvas.h"

using namespace std;

int main()
{
    Canvas c1(100, 100);
    c1.Clear();
    c1.DrawLine(1, 1, 1,6,'*');
    c1.DrawCircle(13, 13, 5, 'c');
    c1.DrawLine(10, 3, 15, 8, '+');
    //c1.FillRect(1, 1, 10, 5,48);
    //c1.FillCircle(50, 50, 10, 48);
    //c1.DrawCircle(50, 50, 10, 48);

    c1.Print();
}