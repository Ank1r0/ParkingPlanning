#pragma once
#include <string>
#include "Ticket.h"
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
    
    int add(const std::string& key, const T& data);
    int del(std::string _key);
    int check(std::string _key);
    T get(std::string _key);
    
private:
    T getN(int index);
    int reindex();
    int hashfunc(const std::string& input);

};
