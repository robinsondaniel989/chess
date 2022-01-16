#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Rook
{
public:
	string name;
	string id;
	Rook(int _id);
	string getName();
	void capName();
};
