#include "Bishop.h"

Bishop::Bishop(int _id) {
	name = "bishop";
	id = name.at(0) + to_string(_id);
}

string Bishop::getName() {
	return name;
}

void Bishop::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

int Bishop::move(int y, int x, int y2, int x2, vector<vector<string>> chessBoard, bool _move) {
	//restricts bishop's movement to diagonal only
	if (abs(x - x2) == abs(y2 - y)) {
		//checks that bishop is taking a clear path
		bool valid = clearPath(x, y, x2, y2, chessBoard);
		//if move var is true, then we're trying to move bishop
		if (_move && valid) {
			if (chessBoard[y2][x2] == "KING" || chessBoard[y2][x2] == "king") {
				cout << "king";
				return 2;
			}
			else {
				return 1;
			}
		}
		else if (_move) {
			cout << "Move path was not open\n";
			return 0;
		}
	}
	else {
		if (_move)
		cout << "Violation- a bishop cannot move like that\n";
		return 0;
	}
}

bool Bishop::clearPath(int x, int y, int x2, int y2, vector<vector<string>> chessBoard) {
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
	if (valid == 0) {
		return true;
	}
	else {
		return false;
	}
}
