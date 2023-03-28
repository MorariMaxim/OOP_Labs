#include <vector> 
#include "Weather.h"
#include "Volvo.h"
#include "BMW.h"
#include "RangeRover.h"
#include "Seat.h"
#include "Fiat.h"
struct Result
{
	Car* car;
	bool finished;
	float time;
};

class Circuit {

	std::vector<Car*> cars; 
	std::vector<Result*> results;
	Weather weather;
	int length;
public:
	void AddCar(Car* thecar);
	void SetLength(int x);
	void SetWeather(Weather weath);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};