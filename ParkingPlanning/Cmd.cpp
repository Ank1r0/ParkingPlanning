#include "Cmd.h"


Cmd::Cmd() // * - add, = end of day
{
	time = 0;
	plate = "";
	type = 'f';
	msg = "";
}

Cmd* Cmd::parse(string input) {
	Cmd* cmd = new Cmd();

	int M = 0, H = 0;
	char cmdtype = 'f';

	if (input.size() < 6)
	{
		cmd->msg = "Message is not correct";
		return cmd;
	}

	size_t found = input.find(":");
	if (found != string::npos)
	{
		H = stoi(input.substr(0, found));
		M = stoi(input.substr(found + 1, found + 2));

		if (H < 0 || H >= 24)
		{
			cmd->msg = "Hours are not correct.";
			return cmd;
		}

		if (M < 0 || M >= 60)
		{
			cmd->msg = "Minutes are not correct.";
			return cmd;
		}
	}
	else
	{
		cmd->msg = "time is not correct";
		return cmd;
	}

	if (found + 4 < input.size())
	{
		cmdtype = input.at(found + 4);

		switch (cmdtype)
		{
		case '*':
			if (found + 6 > input.size() - 1)
			{
				cmd->msg = "name error";
			}
			cmd->plate = input.substr(found + 6, input.size() - 1);
			cmd->type = '*';
			break;
		case '=':
			cmd->type = '=';
			break;
		case '-':
			cmd->type = '-';
			break;
		}


	}
	else {
		cmd->msg = "Wrong input";
		return cmd;
	}

	cmd->time = H * 60 + M;

	return cmd;

}