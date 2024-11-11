#include "Car.h"

Car::Car(string _name, int _IOtime)
{
	name = _name;
	allmin = 0;
	IOtime = _IOtime;
	onpark = true;
} 

Car::Car(string _name, int _IOtime, unsigned long _allmin)
{
	name = _name;
	allmin = 0;
	IOtime = _IOtime;
	onpark = true;
	allmin = _allmin;
}

string Car::plate()
{
	return name;
}