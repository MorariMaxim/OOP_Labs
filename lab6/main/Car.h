#ifndef car_h
#define car_h

class Car {
protected:
	int fuel;
	int consumption;
	int speed[3];
	const char* name;
public:	 
	virtual int getFuel() =0;
	virtual int getSpeed(int x) =0;
	virtual int getConsumption() =0;
	virtual const char* getName()=0;

}; 
#endif car_h