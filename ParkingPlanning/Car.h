#pragma once
#include <string>

using namespace std;

class Car
{	public:
	string name;
	bool onpark;	
	unsigned long allmin;
	int IOtime;

public:
	Car();
	Car(string _name,int _IOtime);
	Car(string _name,int _IOtime, unsigned long allmin);
	~Car();

	string plate();

};
