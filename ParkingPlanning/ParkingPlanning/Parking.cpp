#include "Parking.h"
#include <string>
#include <iostream>
#include "Hashtable.h"
#include "Cmd.h"


string Parking::minToHM(int number)
{
	int M;

	string sM = to_string(number % 60);
	if (sM.length() < 2)
		 sM.insert(sM.begin(), '0');
	return to_string(number / 60)+":"+sM;
}
using namespace std;

int Parking::list(int cmdTime){
	vector<Car*> temp = park.getAll();
	Car* buff1;
	for (size_t i = 1; i < temp.size(); i++)
	{
		for (size_t j = i; j > 0; j--)
		{
			if (j > 0 && temp.at(j)->allmin < temp.at(j - 1)->allmin)
			{
				buff1 = temp.at(j);
				temp.at(j) = temp.at(j - 1);
				temp.at(j - 1) = buff1;

			}
		} 
	}
	
	for (int i = 0; i < temp.size(); i++)
	{
		cout << "Car on parking: " << (temp.at(i)->onpark ? "Yes" : "No") << ", plate:" << temp.at(i)->name << ", overall time:" << (temp.at(i)->onpark ? (temp.at(i)->allmin + cmdTime - temp.at(i)->IOtime) : (temp.at(i)->allmin)) << endl;
	}
	return 4;
}


int Parking::rezero() { 
	vector<Car*> temp = park.getAll();
	
	for (int i = 0; i < temp.size(); ++i)
	{
		
		if (park.getN(i)->onpark)
		{
			park.getN(i)->allmin += 1440 - park.getN(i)->IOtime;
			park.getN(i)->IOtime = 0;
		}
		
	}

	list(0);

	return 2;
}

int Parking::checkpoint(Cmd &cmd)
{
	if (park.isExist(cmd.plate)) {

		Car* temp = park.get(cmd.plate);

		if (temp->onpark == true)
		{
			temp->allmin += cmd.time - temp->IOtime;
			temp->onpark = false;

			cout << "car removed, min on park: " << temp->allmin << endl;
		}
		else
		{
			temp->IOtime = cmd.time;
			temp->onpark = true;
			cout << "Car added" << endl;
		}
		park.add(cmd.plate, temp);

	}
	else
	{
		park.add(cmd.plate, new Car(cmd.plate, cmd.time));
		cout << "car added." << endl;
	}
	return 1;
}

int Parking::action(Cmd &cmd) {
	switch (cmd.type)
	{	
	case '*':
		return checkpoint(cmd);
	case '=':
		return rezero(); //2	
	case '-':
		cout << "Exit initiated.\n";
		return 0;
	case 'l':
		return list(cmd.time);
	default:
		cout << "Command not in list\n";
		return 3;
	}
}

int Parking::errorParser(Cmd& cmd)
{
	switch (cmd.type)
	{
	case 'f':
		cout << "Message is not correct\n";
		return -1;
	case 'H':
		cout << "Hours is not correct\n";
		return -1;
	case 'M':
		cout << "Minutes is not correct\n";
		return -1;
	case 'T':
		cout << "Time is not correct\n";
		return -1;
	case 'N':
		cout << "Name is not correct\n";
		return -1;
	}
}

void Parking::run() {

	bool exitcmd = false;
	string input;
	Cmd cmd;
	int lastcmdTime = 0;
	cout << "Parking started, enter the command e.g. 13:00 * car1, 1:00 * car1, 0:00 =" << endl;
	while(!exitcmd)
	{
		getline(cin, input);
		
		Cmd::parse(input,cmd);

		if (errorParser(cmd) == -1)
		{
			continue;
		}

		if (cmd.time < lastcmdTime && cmd.type != '=') // prev time check
		{
			cout << "Cannot process dates or times in the past.\n";
			continue;
		}
		lastcmdTime = cmd.time;
		
		switch (action(cmd))
		{		
		case 2:
			lastcmdTime = 0;
			break;
		case 0:
			exitcmd = true;
		default:
			break;
		}

		
		cmd.clear();
	}	
}
 
