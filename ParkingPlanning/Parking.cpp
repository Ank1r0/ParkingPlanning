#include "Parking.h"
#include <string>
#include <iostream>
using namespace std;

 char Parking::run() {

	 string input;
	 int M = 0, H = 0,pt = 0;
	 
	 char cmd = 'n';
	 unsigned int allM = 0;
	 string name;
	 while (true)
	 {
		 getline(cin, input);

		 if (input.size() < 6)
		 {
			 cout << "Message is not correct" << endl;
			 continue;
		 }

		 size_t found = input.find(":");
		 if (found != string::npos)
		 {
			 H = stoi(input.substr(0, found));
			 M = stoi(input.substr(found + 1, found + 2));

			 if (H < 0 || H >= 24)
			 {
				 cout << "Hours are not correct." << endl;
				 continue;
			 }

			 if (M < 0 || M >= 60)
			 {
				 cout << "Minutes are not correct." << endl;
				 continue;
			 }
			 
			 if ((H * 60 + M) < pt)
			 {
				cout << "prev time" << endl;
				continue;

			 }
			 else
			 {
				 pt = H * 60 + M;
			 }

			 
		 }
		 else
		 {
			 cout << "time is not correct" << endl;
			 continue;
		 }

		 if (found + 4 < input.size())
		 {
			 cmd = input.at(found + 4);
		 }
		 else {
			 cout << "Not correct command" << endl;
			 continue;
			 
		 }
		 
		 switch (cmd) {
			case '*':
				

				if (found + 6 > input.size() - 1)
				{
					cout << "name error" << endl;
					continue;
				}
				name = input.substr(found+6,input.size()-1);
				cout << "Car added, plate: '" << name <<'\'' << endl;
				 break;
			case '=':
				if (H != 0 || M != 0)
					pt = 0;
					cout << "End of day only 0:00 time can be used." << endl;
					continue;
				 break;
			default:

					 cout << "command out of list" << endl;
				 continue;
				 
		 }
		 cout << "Hours: " << H << endl;
		 cout << "Minutes: " << M << endl;
		 cout << "cmd:" << cmd << endl;

		

	 }
	 

	 
	 
	 return 'k';
}
