#include "Volvo.h"

Volvo::Volvo() {

    name = "Volvo";
    speed[0] = 4;
    speed[1] = 1;
    speed[2] = 1;
    fuel = 100;
    consumption = 6;

}

int Volvo::getFuel()
{
    return fuel;
}

int Volvo::getSpeed(int x)
{
    if (x >= 0 && x <= 2)
    return speed[x];
    return -1;
}

int Volvo::getConsumption()
{
    return consumption;
}

const char* Volvo::getName()
{
    return name;
}
