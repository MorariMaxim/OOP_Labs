#include "Car.h"
#include "Weather.h"
class BMW : public Car {
public:
	BMW();
	int getFuel();
	int getSpeed(int x);
	int getConsumption();
	const char* getName();
};