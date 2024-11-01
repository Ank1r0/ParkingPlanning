

#include <iostream>
#include "Parking.h"
#include "iostream"
#include "Hashtable.h"
#include "Car.h"
using namespace std;

int main()
{   
    //Parking::run();
    Hashtable<Car*> park;
    Car* a = new Car("Car1",10);
    Car* b = new Car("Car2",10);
    park.add("13", a);
    park.add("13", b);
    cout << park.get("13")->name;
}

