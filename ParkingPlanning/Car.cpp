#include "Car.h"

Car::Car(string _name, int _IOtime)
{
	name = _name;
	allmin = 0;
	IOtime = _IOtime;
	onpark = true;
} 

string Car::plate()
{
	return name;
}