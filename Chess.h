#pragma once
#include <string>
#include <vector>
using namespace std;

class Chess
{
public:
	string  name;
	Chess();
	Chess(string sName);
	string getName();
	void setName(string _name);
	vector<vector<Chess>> newGame();
	void printBoard(vector<vector<Chess>>);
	vector<vector<Chess>> movePiece(vector<vector<Chess>> chessBoard, int player);
	bool clearPath(vector<vector<Chess>> chessBoard, int y, int x, int y2, int x2);

};

