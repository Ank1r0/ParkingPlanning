#include "Cmd.h"
#include <iostream>
#include <sstream>



Cmd::Cmd() // * - add, = end of day
{
	time = 0;
	plate = "";
	type = 'f';
	msg = "";
}

Cmd::~Cmd() {}

void Cmd::clear()
{
	time = 0;
	plate = "";
	type = 'f';
	msg = "";
}

void Cmd::parse(string input, Cmd& cmd) {


	int M = 0, H = 0;
	char cmdtype = 'f'; //Message is not correct

	if (input.size() < 6)
	{
		// f
		return;
	}

	size_t found = input.find(":");
	if (found != string::npos)
	{
		H = stoi(input.substr(0, found));
		M = stoi(input.substr(found + 1, found + 2));

		if (H < 0 || H >= 24)
		{
			cmd.type = 'H'; //H
			return;
		}

		if (M < 0 || M >= 60)
		{
			cmd.type = 'M';//M
			return;
		}
	}
	else
	{
		cmd.msg = 'T'; //T
		return;
	}

	if (found + 4 < input.size())
	{
		cmdtype = input.at(found + 4);

		switch (cmdtype)
		{
		case '*':
			if (found + 6 > input.size() - 1)
			{
				cmd.msg = 'N';
			}
			cmd.plate = input.substr(found + 6, input.size() - 1);
			cmd.type = '*';
			break;
		case '=':
			cmd.type = '=';
			break;
		case '-':
			cmd.type = '-';
			break;
		case 'l':
			cmd.type = 'l';
			break;
		}


	}
	else {
		cmd.msg = "Wrong input";
		return;
	}
	
	cmd.time = H * 60 + M;
			
	return;

}