#include "Hashtable.h"
#include "Car.h"  


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
int Hashtable<T>::add(const std::string& _key, const T& _data) {
    if (_key.empty()) {
        return -1;
    }

    int index = hashfunc(_key);

    if (index < 0 || index >= capacity_) {
        return -1;
    }

    if (db[index] == nullptr) {
        db[index] = new element(_key, _data);  
        size_++;  
        return 0;  
    }
    else {
        return -1; 
    }
}


template <typename T>
T Hashtable<T>::getN(int index) {
    if (index < 0 || index > capacity_ - 1)
        return nullptr;

    element* temp = db[index];
    return temp->get();
}

template <typename T>
int Hashtable<T>::hashfunc(const std::string& input) {
    int index = 0;
    for (char c : input) {
        index += c * c;  
    }
    return index % capacity_;  
}

template class Hashtable<Car*>;  
