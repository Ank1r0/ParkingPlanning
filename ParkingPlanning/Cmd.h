#pragma once
#include <string>
#include <iostream>
using namespace std;
class Cmd
{
public:
	int time;
	string plate;
	char type;
	string msg;

	Cmd();
	~Cmd();

	static Cmd* parse(string input);
};

