#include "Car.h"
#include "Weather.h"
class Volvo : public Car {
	
public:
	Volvo();
	int getFuel();
	int getSpeed(int x);
	int getConsumption();
	const char* getName();
};