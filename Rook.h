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
	bool clearPath(int x, int y, int x2, int y2, vector<vector<string>> chessBoard);
};
