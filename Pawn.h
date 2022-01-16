#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class Pawn
{
public:
	string name;
	string id;
	Pawn(int _id);
	string getName();
	void capName();
};

