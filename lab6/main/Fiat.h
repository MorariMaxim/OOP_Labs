#include "Car.h"
#include "Weather.h"
class Fiat : public Car {

public:
	Fiat();
	int getFuel();
	int getSpeed(int x);
	int getConsumption();
	const char* getName();
};