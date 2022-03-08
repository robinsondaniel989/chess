#include "Queen.h"

Queen::Queen(int _id) {
	name = "queen";
	id = name.at(0) + to_string(_id);
}

string Queen::getName() {
	return name;
}

void Queen::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

int Queen::move(int x, int y, int x2, int y2, vector<vector<string>> chessBoard, bool _move) {
	//restricting queen's movement to that of rook and bishop combined
	if (abs(x - x2) == abs(y2 - y) || (x == x2) || (y == y2)) {
		//checks queen's clear path function
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
			cout << "Violation- a queen cannot move like that\n";
		return 0;
	}
}

bool Queen::clearPath(int x, int y, int x2, int y2, vector<vector<string>> chessBoard) {
	int valid = 0;
	//moving up-left diagonally
	if ((y > y2) && (x > x2)) {
		x--; y--;
		while (y > y2) {
			if (chessBoard[x][y] != "") {
				valid++;
			}
			x--; y--;
		}
	}
	//moving down-left diagonally
	else if ((y > y2) && (x < x2)) {
		x++; y--;
		while (x < x2) {
			if (chessBoard[x][y] != "") {
				valid++;
			}
			x++; y--;
		}
	}
	//moving down-right diagonally
	else if ((y < y2) && (x < x2)) {
		x++; y++;
		while (x < x2) {
			if (chessBoard[x][y] != "") {
				valid++;
			}
			x++; y++;
		}
	}
	//moving up-right diagonally
	else if ((y < y2) && (x > x2)) {
		x--; y++;
		while (x > x2) {
			if (chessBoard[x][y] != "") {
				valid++;
			}
			x--; y++;
		}
	}
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

