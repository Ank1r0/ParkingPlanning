#include "Parking.h"
#include <string>
#include <iostream>
#include "Hashtable.h"
#include "Cmd.h"

using namespace std;
int Parking::rezero() {
	//park.getAll();
	
	
	for (int i = 0; i < park.getcap(); ++i)
	{
		if (park.getN(i) != nullptr)
		{
			if (park.getN(i)->onpark)
			{
				park.getN(i)->allmin += 1440 - park.getN(i)->IOtime;
				park.getN(i)->IOtime = 0;
			}
			cout << "Car on parking: " << (park.getN(i)->onpark ? "Yes" : "No") << ", plate:" << park.getN(i)->name << ", overall time:" << park.getN(i)->allmin << endl;
		}
	}
	return 2;
}

int Parking::checkpoint(Cmd* cmd)
{
	if (park.isExist(cmd->plate)) {

		Car* temp = park.get(cmd->plate);

		if (temp->onpark == true)
		{
			temp->allmin += cmd->time - temp->IOtime;
			temp->onpark = false;

			cout << "car removed, min on park: " << temp->allmin << endl;
		}
		else
		{
			temp->IOtime = cmd->time;
			temp->onpark = true;
			cout << "Car added" << endl;
		}
		park.add(cmd->plate, temp);

	}
	else
	{
		park.add(cmd->plate, new Car(cmd->plate, cmd->time));
		cout << "car added." << endl;
	}
	return 1;
}

int Parking::action(Cmd* cmd) {
	switch (cmd->type)
	{
	case '*':
		return checkpoint(cmd);
	case '=':
		return rezero(); //2	
	case '-':
		cout << "Exit initiated.\n";
		return 0;
	default:
		cout << "Command not in list\n";
		return 3;
	}
}

void Parking::run() {

	bool exitcmd = false;
	string input;
	Cmd* cmd = new Cmd();
	Cmd cmd1;
	int lastcmdTime = 0;
	
	while(!exitcmd)
	{
		getline(cin, input);

		cmd = Cmd::parse(input, cmd1);

		if (cmd->time < lastcmdTime && cmd->type != '=') // prev time check
		{
			cout << "cmd: " << cmd->type << endl;
			cout << "msg: " << cmd->msg << endl;
			cout << "plate: " << cmd->plate << endl;
			cout << "time: " << cmd->time << endl;
			cout << "Cannot process dates or times in the past.\n";
			continue;
		}
		lastcmdTime = cmd->time;
		
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
		
	}	
}
 
