#include "Parking.h"
#include <string>
#include <iostream>
#include "Hashtable.h"
using namespace std;

 char Parking::run() {

	 Hashtable<Car*> park;
	/* Car* a = new Car("Car1", 10);
	 Car* b = new Car("Car2", 10);
	 park.add("13", a);
	 park.add("13", b);
	 cout << park.get("13")->name;*/

	 Car* temp = new Car("", 0);
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
		 if(cmd != '=')
		 if ((H * 60 + M) < pt)
		 {
			 cout << "prev time" << endl;
			 continue;

		 }
		 else
		 {
			 pt = H * 60 + M;
		 }
		 
		 switch (cmd) {
			case '*':
				

				if (found + 6 > input.size() - 1)
				{
					cout << "name error" << endl;
					continue;
				}
				name = input.substr(found+6,input.size()-1);	

				if (park.isExist(name)) {

				
					temp = park.get(name);

					if (temp->onpark == true)
					{
						temp->allmin += pt - temp->IOtime;
						temp->onpark = false;

						cout << "car removed, min on park: " << temp->allmin << endl;
						
					}
					else 
					{
						temp->IOtime = pt;
						temp->onpark = true;
						cout << "Car added" << endl;
						
					}
					park.add(name, temp);

				}
				else
				{
					park.add(name, new Car(name, pt));
					cout << "car added." << endl;
				}
				 break;
			case '=':				
					pt = 0;
					
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
					continue;
				 break;
			default:
				
					 cout << "command out of list" << endl;
				 continue;
				 
		 }
	 }	 
	 return 'k';
}
