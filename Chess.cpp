#include "Chess.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

Chess::Chess() {
	Chess::name = "";
}

Chess::Chess(string sName) {
	Chess::name = sName;
}
string Chess::getName() {
	return name;
}

void Chess::setName(string _name) {
	name = _name;
}

vector<vector<Chess>> Chess::newGame()
{
	vector<vector<Chess>> teams(2, vector<Chess>(16));
	vector<vector<Chess>> chessBoard(8, vector<Chess>(8));
	vector<Chess> pieces(16);
	vector<string> pieceNames = { "rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook", "pawn" };
	for (int i = 0; i < 8; i++) {
		Chess piece(pieceNames[i]);
		teams[0][i] = piece;
	}
	for (int i = 8; i < 16; i++) {
		Chess piece(pieceNames[8]);
		teams[0][i] = piece;
	}
	for (int i = 0; i < 8; i++) {
		chessBoard[7][i] = teams[0][i];
	}
	for (int i = 0; i < 8; i++) {
		chessBoard[6][i] = teams[0][i + 8];
	}
	for (int i = 8; i < 16; i++) {
		transform(pieceNames[8].begin(), pieceNames[8].end(), pieceNames[8].begin(), ::toupper);
		Chess piece(pieceNames[8]);
		teams[1][i] = piece;
	}
	for (int i = 0; i < 8; i++) {
		transform(pieceNames[i].begin(), pieceNames[i].end(), pieceNames[i].begin(), ::toupper);
		Chess piece(pieceNames[i]);
		teams[1][i] = piece;
	}
	for (int i = 0; i < 8; i++) {
		chessBoard[1][i] = teams[1][i + 8];
	}
	for (int i = 0; i < 8; i++) {
		chessBoard[0][i] = teams[1][i];
	}
	return chessBoard;
}

void Chess::printBoard(vector<vector<Chess>> chessBoard) {
	vector<string> letters{ " ", "a", "b", "c", "d", "e", "f", "g", "h" };
	for (string x : letters) {
		cout << x << "\t";
	}
	cout << endl;
	for (size_t i = 0; i < 8; i++) {
		cout << (i + 1) << "\t";
		for (size_t j = 0; j < 8; j++) {
			cout << chessBoard[i][j].getName() << "\t";
		}
		cout << endl;
	}
}

vector<vector<Chess>> Chess::movePiece(vector<vector<Chess>> chessBoard, int player) {
	int y, y2;
	char x, x2;
	cout << "Select a piece to move (letter first): ";
	cin >> x >> y;
	cout << "Select a square to move it to (letter first): ";
	cin >> x2 >> y2;
	y--; y2--;
	x2 -= 97; x -= 97;
	string yourPiece = chessBoard[y][x].getName();
	string destination = chessBoard[y2][x2].getName();
	if (yourPiece == "") {
		cout << "You must select a piece\n";
	}
	else {
		if (isupper(yourPiece[0])) {
			cout << "You cannot move an opponent's piece, try again.\n";
		}
		else if (islower(destination[0])) {
			cout << "You cannot move one of your pieces to a space that contains one of your pieces, try again.\n";
		}
		else {
			if (yourPiece == "pawn") {
				if (abs(x - x2) >= 2 || (abs(x2 - x) == 1 && destination == "")) {
					cout << "Violation- a pawn cannot move like that\n";
				}
					else if ((y - y2) == 2 && y == 6 || (y - y2) == 1) {
						chessBoard[y2][x2] = chessBoard[y][x];
						chessBoard[y][x].setName("");
					}
					else if ((x2 - x) == 1 && destination != "") {
						chessBoard[y2][x2] = chessBoard[y][x];
						chessBoard[y][x].setName("");
					}
					else {
						cout << "Violation- a pawn cannot move like that\n";
					}
				}
				else if (yourPiece == "rook") {
					if (y != y2 && x != x2) {
						cout << "Violation- a rook cannot move like that\n";
					}
					else {
						bool valid = clearPath(chessBoard, y, x, y2, x2);
						if (valid) {
							chessBoard[y2][x2] = chessBoard[y][x];
							chessBoard[y][x].setName("");
						}
						else {
							cout << "Move path was not open\n";
						}
					}
				}



				else if (yourPiece == "knight") {
					if (abs(y - y2) >= 2 && abs(x2 - x) >= 2) {
						cout << "Violation- a knight cannot move like that\n";
					}
					else if (abs(y - y2) <= 1 && abs(x2 - x) <= 1) {
						cout << "Violation- a knight cannot move like that\n";
					}
					else {
						chessBoard[y2][x2] = chessBoard[y][x];
						chessBoard[y][x] = Chess();
					}
				}
				else if (yourPiece == "bishop") {
				if (abs(y - y2) == abs(x2 - x)) {
					bool valid = clearPath(chessBoard, y, x, y2, x2);
					if (valid) {
						chessBoard[y2][x2] = chessBoard[y][x];
						chessBoard[y][x].setName("");
					}
					else {
						cout << "Move path was not open\n";
					}
				}
				else {
					cout << "Violation- a bishop cannot move like that\n";					
					}
				}
				else if (yourPiece == "queen") {
					if (abs(y - y2) == abs(x2 - x) || y == y2 || x == x2) {
						bool valid = clearPath(chessBoard, y, x, y2, x2);
						if (valid) {
							chessBoard[y2][x2] = chessBoard[y][x];
							chessBoard[y][x].setName("");
						}
						else {
							cout << "Move path was not open\n";
						}
					}
					else {
						cout << "Violation- a queen cannot move like that\n";
					}
				}
				else if (yourPiece == "king") {
					if ((y - y2) <= 1 && (x2 - x) <= 1) {
						chessBoard[y2][x2] = chessBoard[y][x];
						chessBoard[y][x] = Chess();
					}
					else {
						cout << "Violation- a king cannot move like that\n";
					}
				}
			}
		}
	return chessBoard;
}

bool Chess::clearPath(vector<vector<Chess>> chessBoard, int y, int x, int y2, int x2) {	
	int valid = 0;
		if (y > y2) {
			if (x < x2) {
				while (y > y2) {
					string square = chessBoard[(y - 1)][(x + 1)].getName();
					if (square != "") {
						valid++;
					}
					y--;
					x++;
				}
			}
			else if (x > x2) {
				while (y > y2) {
					string square = chessBoard[(y - 1)][(x - 1)].getName();
					if (square != "") {
						valid++;
					}
					y--;
					x--;
				}
			}
			else {
				while (y > y2) {
					string square = chessBoard[(y - 1)][x].getName();
					if (square != "") {
						valid++;
					}
					y--;
				}
			}
		} if (y < y2) {
			if (x < x2) {
				while (y < y2) {
					string square = chessBoard[(y + 1)][(x + 1)].getName();
					if (square != "") {
						valid++;
					}
					y++;
					x++;
				}
			}
			else if (x > x2) {
				while (y < y2) {
					string square = chessBoard[(y + 1)][(x - 1)].getName();
					if (square != "") {
						valid++;
					}
					y++;
					x--;
				}
			}
			else {
				while (y < y2) {
					string square = chessBoard[(y + 1)][x].getName();
					if (square != "") {
						valid++;
					}
					y++;
				}
			}
		}
		else if (x > x2) {
			do {
				string square = chessBoard[y][(x-1)].getName();
				if (square != "") {
					valid++;
				}
				x--;
			} while (x > x2);
		} else if (x < x2) {
			do {
				string square = chessBoard[y][(x+1)].getName();
				if (square != "") {
					valid++;
				}
				x++;
			} while (x < x2);
		}
		if (valid != 0) {
			return false;
		}
		else {
			return true;
		}
	}

void Chess::checkMate(vector<vector<Chess>> chessBoard) {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (islower(chessBoard[i][j].getName()[0])) {
				cout << "There's a " + chessBoard[i][j].getName(); 
				printf(" located at %c%d\n", (j+97), (i+1));

			}
		}
	}
}




