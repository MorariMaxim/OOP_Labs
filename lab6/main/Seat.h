#include "Car.h"
#include "Weather.h"
class Seat : public Car {
public:
	Seat();
	int getFuel();
	int getSpeed(int x);
	int getConsumption();
	const char* getName();
};