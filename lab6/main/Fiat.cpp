#include "Fiat.h"

Fiat::Fiat() {
    name = "Fiat";
    speed[0] = 3;
    speed[1] = 1;
    speed[2] = 1;
    fuel = 100;
    consumption = 1;
}
int Fiat::getFuel()
{
    return fuel;
}

int Fiat::getSpeed(int x)
{
    if (x >= 0 && x <= 2)
        return speed[x];
    return -1;
}

int Fiat::getConsumption()
{
    return consumption;
}

const char* Fiat::getName()
{
    return name;
}
