#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

class King
{
public:
	string name;
	string id;
	King(int _id);
	string getName();
	void capName();
};

