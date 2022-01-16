#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Queen
{
public:
	string name;
	string id;
	Queen(int _id);
	string getName();
	void capName();
};

