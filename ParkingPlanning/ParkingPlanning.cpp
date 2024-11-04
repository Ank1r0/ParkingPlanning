

#include <iostream>
#include "Parking.h"
#include "iostream"
#include "Hashtable.h"
#include "Car.h"
using namespace std;

int main()
{   
    //Parking::run(); 
    Car* a = new Car("ASD", 0);
    Car* b = new Car("AAAA", 0);
    Car* c = new Car("ASV", 0);
    Car* d = new Car("ADSA", 0);

    Hashtable<Car*> park;

    park.add(a->plate(), a);
    park.add(b->plate(), b);
    park.add(c->plate(), c);
    park.add(d->plate(), d);

    

    park.del("ASD");
   
    cout << (park.isExist("AAAA") ? "YES" : "NO") << endl;
    cout << (park.isExist("ASD") ? "YES" : "NO") << endl;
}

