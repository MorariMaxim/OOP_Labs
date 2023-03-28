#include "Circuit.h"
#include <iostream>
void Circuit::AddCar(Car* thecar)
{
	cars.push_back(thecar);
}

void Circuit::SetLength(int x)
{
	length = x;
}

void Circuit::SetWeather(Weather weath)
{
	weather = weath;
}

void Circuit::Race()
{
	float nfuel,fintime;
	int w;
	bool fin;
	if (this->weather == Rain) w = 0;
	if (this->weather == Sunny) w = 1;
	if (this->weather == Snow) w = 2;
	for (Car * a : cars) {
		fintime = length / a->getSpeed(w);
		if (a->getConsumption() * fintime <= a->getFuel()) fin = 1;
		else fin = 0;
		if (fin == 0) fintime = (float)a->getFuel()/a->getConsumption() * a->getSpeed(w);
		results.push_back(new Result{a,fin,fintime});
	}

}

void Circuit::ShowFinalRanks()
{ 
	for (Result * r : results) {
		if (r->finished == 1)
			printf("%s finished at %f\n",r->car->getName(),r->time);
			
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (Result* r : results) {
		if (r->finished == 0)
			printf("%s did not finish and stopped at %f\n", r->car->getName(), r->time);
		
	}
}
