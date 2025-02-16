#include "RangeRover.h"
RangeRover::RangeRover() {
    name = "RangeRover";
    speed[0] = 4;
    speed[1] = 1;
    speed[2] = 1;
    fuel = 100;
    consumption = 1;
}


int RangeRover::getFuel()
{
    return fuel;
}

int RangeRover::getSpeed(int x)
{
    if (x >= 0 && x <= 2)
        return speed[x];
    return -1;
}

int RangeRover::getConsumption()
{
    return consumption;
}

const char* RangeRover::getName()
{
    return name;
}
