#pragma once
#include <string>

template <typename T>
class Hashtable
{
public:
    int capacity_;
    int size_;
    int non_dublicate = 0;
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

   
    Hashtable();
    ~Hashtable();  
    int add(const std::string& key, const T& data);
    //element** getdb();
    int del(std::string _key);
    int check(std::string _key);
    T get(std::string _key);
    T getN(int index);
    int hashfunc(const std::string& input);
};
