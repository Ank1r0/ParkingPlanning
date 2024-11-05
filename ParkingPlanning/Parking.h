#pragma once
#include "Cmd.h"
#include "Car.h"
#include "Hashtable.h"
class Parking
{
public:
	Hashtable<Car*> park;

	static char run2();
	int action(Cmd* cmd);
	int checkpoint(Cmd* cmd);
	int rezero();
	void run();

};

