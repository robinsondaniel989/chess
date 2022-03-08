#include "Rook.h"

Rook::Rook(int _id) {
	name = "rook";
	id = name.at(0) + to_string(_id);
}

string Rook::getName() {
	return name;
}

void Rook::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

int Rook::move(int x, int y, int x2, int y2, vector<vector<string>> chessBoard, bool _move) {
	//rook can only move in straight lines
	if (y == y2 || x == x2) {
		//checks that rook is taking a clear path
		bool valid = clearPath(x, y, x2, y2, chessBoard);
		if (valid) {
			if (_move) {
				return 1;
			}
			else {
				if (chessBoard[x2][y2] == "KING" || chessBoard[x2][y2] == "king") {
					return 2;
				}
				else {
					return 1;
				}
			}
		}
		else {
			if (_move)
				cout << "Move path was not open\n";
			return 0;
		}
	}
	else {
		if (_move)
			cout << "Violation- a rook cannot move like that\n";
		return 0;
	}
}
	

bool Rook::clearPath(int x, int y, int x2, int y2, vector<vector<string>> chessBoard) {
	int valid = 0;
	//moving horizontally
	if (x == x2) {
		//moving left
		if (y > y2) {
			y--;
			while (y > y2) {
				if (chessBoard[x][y] != "") {
					valid++;
				}
				y--;
			}
		}
		//moving right
		else if (y < y2) {
			y++;
			while (y < y2) {
				if (chessBoard[x][y] != "") {
					valid++;
				}
				y++;
			}
		}
	}
	//moving vertically
	else if (y == y2) {
		//moving up
		if (x > x2) {
			x--;
			while (x > x2) {
				if (chessBoard[x][y] != "") {
					valid++;
				}
				x--;
			}
		}
		//moving down
		else if (x < x2) {
			x++;
			while (x < x2) {
				if (chessBoard[x][y] != "") {
					valid++;
				}
				x++;
			}
		}
	}
	if (valid == 0) {
		return true;
	}
	else {
		return false;
	}
}

