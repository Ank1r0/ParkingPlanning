#include "Hashtable.h"
#include "Car.h"  
#include <iostream>

template <typename T>
Hashtable<T>::Hashtable() {
    size_ = 0;
    capacity_ = 100;
    db = new element * [capacity_];

    for (int i = 0; i < capacity_; i++) {
        db[i] = nullptr;
    }
}


template <typename T>
Hashtable<T>::~Hashtable() {
    for (int i = 0; i < capacity_; i++) {
        if (db[i] != nullptr) {
            delete db[i];  
        }
    }
    delete[] db; 
}

template <typename T>
int Hashtable<T>::add(const std::string& _key, const T& _data) { // ADD
    
    if (_key.empty()) {
        return -1;
    }

    int index = hashfunc(_key);
    cout << "index: " << index << endl;
    if (index < 0 || index >= capacity_) {
        return -1;
    }

    if (db[index] == nullptr) {
        db[index] = new element(_key, _data);   
        size_++;  
        return 0;  
    }
    else if (non_dublicate) {
        Car* temp = db[index]->get();
        if (_key.compare(temp->plate) == 0)
        {
            cout << "\"" << temp->plate << "\" already in database" << endl;
            return 2;
        }
    }

    if (db[index] != nullptr) 
    {
        int temp = index;

        while (true)
        {    
            if (db[++temp] == nullptr)
            {
                db[temp] = new element(_key, _data);
                return 0;
            }
        }
        cout << "index already taken" << endl;
    }

    return -1;
}

template <typename T>
T Hashtable<T>::get(string _key) { // GET BY KEY
    int index = hashfunc(_key);
    if (index < 0 || index > capacity_ - 1)
        return nullptr;

    element* temp = db[index];
    return temp->get();
}

template <typename T>
int Hashtable<T>::check(std::string _key)  //CHECK -1 HASHFUNC error, 0 - EMPTY, 1 - exists.
{
    int index = hashfunc(_key);
    if (index < 0 || index > capacity_ - 1)
        return -1;
    if (db[index] == nullptr)
        return 0;
    else return 1;
}

template <typename T>
int Hashtable<T>::del(std::string _key)  // DELETE 0 - Empty, 1 Succesful delete.
{
    int index = hashfunc(_key);
    if (index < 0 || index > capacity_ - 1)
        return -1;
    if (db[index] == nullptr)
        return 0;
    else {
        db[index] = nullptr;
        --size_;
    }

    return 1;
}

template <typename T>
T Hashtable<T>::getN(int index) { // GET BY INDEX
    if (index < 0 || index > capacity_ - 1)
        return nullptr;

    element* temp = db[index];
    return temp->get();
}

template <typename T>
int Hashtable<T>::hashfunc(const std::string& input) { // HASHFUNC
    int index = 0;
    for (char c : input) {
        index += c * c;  
    }
    return index % capacity_;  
}

//template <typename T>
//Hashtable<T>::element** Hashtable<T>::getdb() 
//{ 
//    return db;
//}



template class Hashtable<Car*>;  
