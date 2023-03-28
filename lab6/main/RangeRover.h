#include "Car.h"
#include "Weather.h"
class RangeRover : public Car {
public:
	RangeRover();
	int getFuel();
	int getSpeed(int x);
	int getConsumption();
	const char* getName();
};