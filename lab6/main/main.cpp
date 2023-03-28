#include <iostream>
#include "Circuit.h" 
 

int main()
{
    Circuit c;

    c.SetLength(100);

    c.SetWeather(Weather::Rain);

    c.AddCar(new Volvo());

    c.AddCar(new BMW());

    c.AddCar(new Seat());

    c.AddCar(new Fiat());

    c.AddCar(new RangeRover());

    c.Race();
    c.ShowFinalRanks();
    c.ShowWhoDidNotFinish();
   
} 