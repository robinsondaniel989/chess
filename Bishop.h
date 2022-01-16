#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Bishop
{
public:
	string name;
	string id;
	Bishop(int _id);
	string getName();
	void capName();
};

