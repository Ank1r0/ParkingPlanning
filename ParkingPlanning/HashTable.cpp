#include "Hashtable.h"
#include "Car.h"  
#include <iostream>
#include <vector>

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
Hashtable<T>::Hashtable(int _newcap) {
    if (_newcap < 0)
        return;
    size_ = 0;
    capacity_ = _newcap;
    db = new element * [capacity_];

    for (int i = 0; i < capacity_; i++) {
        db[i] = nullptr;
    }
}

template <typename T>
int Hashtable<T>::reindex()
{
    Hashtable<T> temp(getcap()*2);

    for (size_t i = 0; i < capacity_; i++)
    {
        if (db[i] != nullptr) 
        {   
            temp.add(db[i]->key_, db[i]->get());
            delete db[i];
            db[i] = nullptr;
        }       
    }

    
    std::swap(db, temp.db); 
    delete [] temp.db;
    return 1;
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
int Hashtable<T>::add(const std::string& _key, const T& _data) { // ADD 0 - element added
    
    if (_key.empty()) {
        return -1;
    }

    if (size_ >= (capacity_ / 4) * 3)
    {
        reindex();
    }

    int index = hashfunc(_key) % capacity_;

    while (db[index % capacity_] != nullptr)
    {
        if (_key.compare(db[index % capacity_]->key_) == 0)
        {            
            db[index % capacity_]->data_ = _data;
            return 0;
        }
        ++index;
    }

    db[index % capacity_] = new element(_key, _data);
    size_++;
    return 0;
}

template <typename T>
int Hashtable<T>::getcap() { 
    return capacity_;
}
template <typename T>
int Hashtable<T>::getsize() {
    return size_;
}


template <typename T>
T Hashtable<T>::get(string _key) { // GET BY KEY

    int index = hashfunc(_key) % capacity_;

    while (db[index % capacity_])
    {
        if (!_key.compare(db[index % capacity_]->key_))
        {
            return db[index % capacity_]->data_;
        }
        ++index;
    }

    return nullptr;
}

template <typename T>
bool Hashtable<T>::isExist(std::string _key)  //0 - EMPTY, 1 - exists, -1 not found.
{
    int index = hashfunc(_key) % capacity_;

    while (db[index % capacity_])
    {
        if (!_key.compare(db[index % capacity_]->key_))
        {
            return true;
        }
        ++index;
    }

    return false;
}

template <typename T>
int Hashtable<T>::del(std::string _key)  // DELETE 0 - Empty, 1 Succesful delete.
{   
    unsigned int index = hashfunc(_key) % capacity_,left = index, right = index;

    while (db[left])
    {            
        --left;
        if (left < 0) { left = capacity_ - 1; }
    }

    while (db[right % capacity_])
    {      
        right++;
    }

    vector<element*> temp;
    for (size_t i = left + 1; i < right; i++)
    {        
        if (_key.compare(db[i % capacity_]->key_))
        {
            temp.push_back(db[i % capacity_]);
        }
        else
        {
            db[i % capacity_] = nullptr;
            delete db[i % capacity_];
            continue;
        }
        db[i % capacity_] = nullptr;       
    }

    for (size_t i = 0; i < temp.size(); i++)
    {
        add(temp.at(i)->key_, temp.at(i)->data_);
    }

    return 1;
}

template <typename T>
T Hashtable<T>::getN(int index) { // GET BY INDEX
    index = index % capacity_;

    element* temp = db[index];
    if (temp == nullptr)
    {
        return nullptr;
    }
    return temp->get();
}

template <typename T>
unsigned int Hashtable<T>::hashfunc(const std::string& input) { // HASHFUNC
    unsigned int hash = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        hash += pow( input.at(i) * (i) *input.size(),2);
    }

    return hash;
    //return 99;
}



template class Hashtable< Car *>;
