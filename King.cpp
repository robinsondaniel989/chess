#include "King.h"

King::King(int _id) {
	name = "king";
	id = name.at(0) + to_string(_id);
}

string King::getName() {
	return name;
}

void King::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}
int King::move(int x, int y, int x2, int y2, vector<vector<string>> chessBoard, bool _move) {
	//restricts king to move only space at a time
	if ((y - y2) <= 1 && (x2 - x) <= 1 && (y2 - y) <= 1 && (x - x2) <= 1) {
		if (_move) {
			if (chessBoard[y2][x2] == "KING" || chessBoard[y2][x2] == "king") {
				cout << "king";
				return 2;
			}
			else {
				return 1;
			}
		}
	}
	else {
		if (_move) {
			cout << "Violation, a king cannot move like that\n";
			return 0;
		}
	}
}
