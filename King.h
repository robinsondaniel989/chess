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
	int move(int y, int x, int y2, int x2, vector<vector<string>> chessBoard, bool _move);
};

