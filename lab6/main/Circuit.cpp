#include "Circuit.h"
#include <iostream>
#include <cstdlib>
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
		fintime = (float)length / a->getSpeed(w);
		if (a->getConsumption() * fintime <= a->getFuel()) fin = 1;
		else fin = 0;
		if (fin == 0) fintime = (float)a->getFuel()/a->getConsumption() * a->getSpeed(w);
		results.push_back(new Result{a,fin,fintime});
	}

}

void Circuit::ShowFinalRanks()
{ 
	int i, j,n = results.size();
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++) {			
			if (results[j]->time > results[j + 1]->time) {
				//printf("%f, %f\n", results[j]->time, results[j + 1]->time);
				Result* temp = results[j];
				results[j] = results[j + 1];
				results[j + 1] = temp;
			}
		}
		
	i = 1;
	for (Result * r : results) {
		if (r->finished == 1)
			printf("%d. %s, time:%f\n",i++,r->car->getName(),r->time);
			
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (Result* r : results) {
		if (r->finished == 0)
			printf("%s did not finish\n", r->car->getName());
		
	}
}