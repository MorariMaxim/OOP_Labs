#include "Seat.h"

Seat::Seat() {
    name = "Seat";
    speed[0] = 1;
    speed[1] = 1;
    speed[2] = 1;
    fuel = 100;
    consumption = 1;
}

int Seat::getFuel()
{
    return fuel;
}

int Seat::getSpeed(int x)
{
    if (x >= 0 && x <= 2)
        return speed[x];
    return -1;
}

int Seat::getConsumption()
{
    return consumption;
}

const char* Seat::getName()
{
    return name;
}
