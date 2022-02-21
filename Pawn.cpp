#include "Pawn.h"


Pawn::Pawn(int _id) {
	name = "pawn";
	id = name.at(0) + to_string(_id);
}

string Pawn::getName() {
	return name;
}

void Pawn::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

int Pawn::move(int y, int x, int y2, int x2, vector<vector<string>> chessBoard, bool _move) {
	///restricts pawns from moving too many spaces
	if (abs(x - x2) >= 2 || (abs(x2 - x) == 1 && chessBoard[y2][x2] == "")) {
		if (_move)
		cout << "Violation- a pawn cannot move like that\n";
		return 0;
	}
	//allows pawns to move one space or two spaces if first move
	else if ((y - y2) == 2 && y == 6 || (y2 - y) == 2 && y == 1 || abs(y - y2) == 1 && chessBoard[y2][x2] == "") {
		if (_move) {
			return 1;
		}
	}
	//allows the pawns to capture pieces on the diagonal move
	else if (abs(x2 - x) == 1 && abs(y - y2) == 1 && (chessBoard[y2][x2] != "")) {
		if (_move) {			
			return 1;
		}
		else {
			if (chessBoard[y2][x2] == "KING" || chessBoard[y2][x2] == "king") {
			return 2;
			}
		}
	}
	else {
		return 0;
	}
}
