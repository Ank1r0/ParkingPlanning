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
	
	static void parse(string input, Cmd& cmd);
	//static void parseA(string input, Cmd &cmd);

	void clear();
	
};

