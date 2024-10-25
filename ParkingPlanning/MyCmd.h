#pragma once

#include <string>
#include <iostream>
using namespace std;
class MyCmd
{
public:
	MyCmd() {};

static string parse(std::string input);
};

