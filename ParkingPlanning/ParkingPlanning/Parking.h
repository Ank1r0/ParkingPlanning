#pragma once
#include "Cmd.h"
#include "Car.h"
#include "Hashtable.h"
class Parking
{
public:
	Hashtable<Car*> park;

	int action(Cmd &cmd);
	int checkpoint(Cmd &cmd);
	int errorParser(Cmd &cmd);
	int rezero();
	int list(int cmdTime);
	void run();
	static string minToHM(int number);

};

