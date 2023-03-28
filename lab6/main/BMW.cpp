#include "BMW.h"
BMW::BMW() {
    name = "BMW";
    speed[0] = 1;
    speed[1] = 1;
    speed[2] = 1;
    fuel = 100;
    consumption = 1;
}

int BMW::getFuel()
{
    return fuel;
}

int BMW::getSpeed(int x)
{
    if (x >= 0 && x <= 2)
        return speed[x];
    return -1;
}

int BMW::getConsumption()
{
    return consumption;
}

const char* BMW::getName()
{
    return name;
}
