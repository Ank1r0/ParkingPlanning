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
    
    if (_key.empty() || size_ - 1 == capacity_) {
        return -1;
    }

    if (size_ >= (capacity_ / 4) * 3)
    {
        reindex();
    }

    int index = hashfunc(_key) % capacity_;

    if (db[index] == nullptr) {
        db[index] = new element(_key, _data);   
        size_++;        
        return 0;  
    }   


    if (db[index] != nullptr) 
    {        
        int i = index;
        while (true)
        {   

            if (db[i % capacity_] == nullptr)
            {
                db[i % capacity_] = new element(_key, _data);
                size_++;
                return 0;
            }

            if (_key.compare(db[i % capacity_]->key_) == 0)
            {
                
                db[i % capacity_]->data_ = _data;
                return 0;
            }
         
            ++i;
        }       
    }

    return -1;
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

    element* temp = db[index];

    if (temp == nullptr) {
        return nullptr;
    }

    if (_key.compare(temp->key_) != 0) // переделать тут проверку на nullptr
    {
        int i = index;
       
        while (true)
        {           
            temp = db[i%capacity_];
            
            if (temp == nullptr)
            {
                cout << "notfound" << endl;
                return nullptr;
            }
            
            if (_key.compare(temp->key_) != 0)
            {
                ++i;               
            }

            if (_key.compare(temp->key_) == 0)
            {
                return temp->get();
            }                     
        }
        cout << "taken" << endl;
        return nullptr;
    }
    return temp->get();
}

template <typename T>
bool Hashtable<T>::isExist(std::string _key)  //0 - EMPTY, 1 - exists, -1 not found.
{
    int index = hashfunc(_key)%capacity_;
    
    if (db[index] == nullptr)
        return false;
    if (_key.compare(db[index]->key_) == 0)
        return true;

    element* temp = db[index];

    if (_key.compare(temp->key_) != 0)
    {
        int i = index;

        while (true)
        {
            temp = db[i % capacity_];

            if (temp == nullptr)
            {                
                return false;
            }

            if (_key.compare(temp->key_) != 0)
            {
                ++i;
            }

            if (_key.compare(temp->key_) == 0)
            {              
                return true;
            }
        }
    }

    else return 1;
}

template <typename T>
int Hashtable<T>::del(std::string _key)  // DELETE 0 - Empty, 1 Succesful delete.
{
    int index = hashfunc(_key) % capacity_;

    if (db[index] == nullptr)
        return 0;

    else if (_key.compare(db[index]->key_) == 0) 
    {
        delete db[index];
        db[index] = nullptr;
        --size_;
        return 1;
    }
   
    element* temp = db[index];
    
    if (_key.compare(temp->key_) != 0)
    {
        int i = index;

        while (true)
        {
            temp = db[i % capacity_];           

            if (temp == nullptr)
            {
                cout << "notfound" << endl;
                return -1;
            }

            if (_key.compare(temp->key_) != 0)
            {
                ++i;
            }

            if (_key.compare(temp->key_) == 0)
            {              
                delete db[i % capacity_];
                
                db[i % capacity_] = nullptr;
                --size_;

                return 1;
            }
        }       
    }
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

    //return hash;
    return 1;
}

template class Hashtable< Car *>;
