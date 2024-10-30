#pragma once
#include <string>

using namespace std;

class Vehicle
{ 
	string plate_;
	string model_;
	string color_;
	short year_;

	Vehicle(){}
	Vehicle(string _plate, string _model, string _color, short _year);
	~Vehicle();
};

