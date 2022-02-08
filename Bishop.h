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
	int move(int y, int x, int y2, int x2, vector<vector<string>> chessBoard, bool _move);
	bool clearPath(int x, int y, int x2, int y2, vector<vector<string>> chessBoard);
};

