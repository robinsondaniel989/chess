#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Knight
{
public:
	string name;
	string id;
	Knight(int _id);
	string getName();
	void capName();
};

