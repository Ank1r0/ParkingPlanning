#pragma once
#include <string>
#include "Car.h"
template <typename T>
class Hashtable
{
    int capacity_;
    int size_;
   
    class element {
    public:
        std::string key_;  
        T data_;

        element(const std::string& _key, const T& _data) : key_(_key), data_(_data) {}

        T get() {
            return data_;
        }
    };

    element** db;

public:

    Hashtable();    
    ~Hashtable();  
    int getcap();
    int getsize();
    int add(const std::string& key, const T& data);
    int del(std::string _key);
    bool isExist(std::string _key);
    T get(std::string _key);
    T getN(int index);
private:
    Hashtable(int _newcap);
    int reindex();
    unsigned int hashfunc(const std::string& input);

};
