#include "Knight.h"


Knight::Knight(int _id) {
	name = "knight";
	id = name.at(0) + to_string(_id);
}

string Knight::getName() {
	return name;
}

void Knight::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

int Knight::move(int y, int x, int y2, int x2, vector<vector<string>> chessBoard, bool _move) {
	//restricts knight's movement to L pattern
	if (abs(y - y2) == 2 && abs(x2 - x) == 1) {
		if (_move) {
			return 1;
		}
		else {
			if (chessBoard[y2][x2] == "KING" || chessBoard[y2][x2] == "king") {
				return 2;
			}		
		}
	}
	//restricts knight movement to L pattern
	else if (abs(y - y2) == 1 && abs(x2 - x) == 2) {
		if (_move) {
			return 1;
		}
		else {
			if (chessBoard[y2][x2] == "KING" || chessBoard[y2][x2] == "king") {
				return 2;
			}
		}
	} else {
		if (_move) {
			cout << "Violation, a knight cannot move like that\n";
			return 0;
		}
	}
}


