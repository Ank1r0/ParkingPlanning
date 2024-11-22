

#include <iostream>
#include "Parking.h"
#include "iostream"
#include "Hashtable.h"
#include "Car.h"
using namespace std;

int main()
{   
    //cout << Parking::minToHM(13131) << endl;
    //Parking a;

  
  
   // a.run();

 
     
     //cout << b.getAll()[1]->key_;



   // Parking::run(); 
    
    Car* a = new Car("A", 0,10);
    Car* b = new Car("B", 0,20);
    Car* c = new Car("C", 0,30);
    Car* d = new Car("D", 0,40);
    Car* a1 = new Car("A1", 0,10);
    Car* b1 = new Car("B1", 0,20);
    Car* c1 = new Car("C1", 0,30);
    Car* d1 = new Car("D1", 0,40);
    Car* a2 = new Car("A2", 0,10);
    Car* b2 = new Car("B2", 0,20);
    Car* c2 = new Car("C2", 0,30);
    Car* d2 = new Car("D2", 0,40);

    Hashtable<Car*> park;
    park.add(a->plate(), a);
    park.add(b->plate(), b);
    park.add(c->plate(), c);
    park.add(d->plate(), d);
    park.add(a1->plate(), a1);
    park.add(b1->plate(), b1);
    park.add(c1->plate(), c1);
    park.add(d1->plate(), d1);
    park.add(a2->plate(), a2);
    park.add(b2->plate(), b2);
    park.add(c2->plate(), c2);
    park.add(d2->plate(), d2);

    
    
    
    cout << "Before test\n";
    vector<Car*> vec = park.getAll();

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i)->name << endl;
    }
    cout << "TEST0\n-----------------------\n";
    cout << "del:" << park.del("C") << endl;

    vec = park.getAll();

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i)->name << endl;
    }
    cout << "-----------------------\n";

    cout << "TEST1\n-----------------------\n";
    cout << "del:" << park.del("C1") << endl;

    vec = park.getAll();

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i)->name << endl;
    }

    cout << "-----------------------\n";

    cout << "TEST2\n-----------------------\n";
    cout << "del:" << park.del("C2") << endl;

    vec = park.getAll();

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i)->name << endl;
    }
    cout << "-----------------------\n";
   /* cout << (park.isExist("AAAA") ? "YES" : "NO") << endl;
    cout << (park.isExist("ASD") ? "YES" : "NO") << endl;*/
}

