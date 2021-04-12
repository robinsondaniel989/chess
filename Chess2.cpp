#include "Chess2.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


Chess2::Chess2() {
	vector<vector<string>> chessBoard2(8, vector<string>(8));
	vector<vector<string>> teams(2, vector<string>(16));
	vector<string> pieceNames2 = { "rook", "knight", "bishop", "queen", "king", "bishop", "knight", "rook", "pawn" };
	for (int i = 0; i < 8; i++) {
		teams[0][i] = pieceNames2[i];
	}
	for (int i = 8; i < 16; i++) {
		teams[0][i] = pieceNames2[8];
	}
	for (int i = 0; i < 8; i++) {
		chessBoard2[7][i] = teams[0][i];
	}
	for (int i = 0; i < 8; i++) {
		chessBoard2[6][i] = teams[0][i + 8];
	}
	for (int i = 8; i < 16; i++) {
		transform(pieceNames2[8].begin(), pieceNames2[8].end(), pieceNames2[8].begin(), ::toupper);
		teams[1][i] = pieceNames2[8];
	}
	for (int i = 0; i < 8; i++) {
		transform(pieceNames2[i].begin(), pieceNames2[i].end(), pieceNames2[i].begin(), ::toupper);
		teams[1][i] = pieceNames2[i];
	}
	for (int i = 0; i < 8; i++) {
		chessBoard2[1][i] = teams[1][i + 8];
	}
	for (int i = 0; i < 8; i++) {
		chessBoard2[0][i] = teams[1][i];
	}
	for (unsigned int x = 0; x < pieceNames2.size(); x++) {
		transform(pieceNames2[x].begin(), pieceNames2[x].end(), pieceNames2[x].begin(), ::tolower);
	}
	pieceNames = pieceNames2;
	chessBoard = chessBoard2;
	move = true;
	kingCheck = false;
	lowerCase = true;
	goodMove = false;
}

void Chess2::setMove(bool _move) {
	move = _move;
}

void Chess2::setCase(bool _case) {
	lowerCase = _case;
}

bool Chess2::getCase() {
	if (lowerCase) {
		cout << "it's lower's turn" << endl;
	}
	else {
		cout << "It's upper's turn" << endl;
	}
	return lowerCase;
}

void Chess2::printBoard() {
	vector<string> letters{ " ", "a", "b", "c", "d", "e", "f", "g", "h" };
	for (string x : letters) {
		cout << x << "\t";
	}
	cout << endl;
	for (size_t i = 0; i < 8; i++) {
		cout << (i + 1) << "\t";
		for (size_t j = 0; j < 8; j++) {
			cout << chessBoard[i][j] << "\t";
		}
		cout << endl;
	}
}



void Chess2::movePiece(char x, int y, char x2, int y2) {
	y--; y2--;
	x2 -= 97; x -= 97;
	string yourPiece = chessBoard[y][x];
	string destination = chessBoard[y2][x2];
	if (isupper(yourPiece[0]) && move) {
		cout << "You've selected an upper piece" << endl;;
	}
	else if (islower(yourPiece[0]) && move) {
		cout << "You've selected a lower piece" << endl;
	}
	if (isupper(destination[0]) && move) {
		cout << "You're moving to an upper piece" << endl;;
	}
	else if (islower(destination[0]) && move) {
		cout << "You're moving to a lower piece" << endl;
	}
	if (yourPiece == "" && move) {
		cout << "You must select a piece\n";
	}
	else {
		if ((isupper(yourPiece[0]) && move && lowerCase) || (islower(yourPiece[0]) && move && !lowerCase)) {
			cout << "You cannot move an opponent's piece, try again.\n";
		}
		else if ((islower(destination[0]) && move && lowerCase) || (isupper(destination[0]) && move && !lowerCase)) {
			cout << "You cannot move one of your pieces to a space that contains one of your pieces, try again.\n";
		}
		else {
			if (yourPiece == pieceNames[8]) {
				pawnMove(y, x, y2, x2);
			}
			else if (yourPiece == pieceNames[0]) {
				rookMove(y, x, y2, x2);
			}
			else if (yourPiece == pieceNames[1]) {
				knightMove(y, x, y2, x2);
			}
			else if (yourPiece == pieceNames[2]) {
				bishopMove(y, x, y2, x2);
			}
			else if (yourPiece == pieceNames[3]) {
				queenMove(y, x, y2, x2);
			}
			else if (yourPiece == pieceNames[4]) {
				kingMove(y, x, y2, x2);
			}
		}
	}
}

void Chess2::changeTurn() {
	if (lowerCase) {
		for (int i = 0; i <= 8; i++) {
			transform(pieceNames[i].begin(), pieceNames[i].end(), pieceNames[i].begin(), ::toupper);
			lowerCase = false;
		}
	}
	else {
		for (int i = 0; i <= 8; i++) {
			transform(pieceNames[i].begin(), pieceNames[i].end(), pieceNames[i].begin(), ::tolower);
			lowerCase = true;
		}
	}
}

void Chess2::findKing() {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (chessBoard[i][j] == "KING") {
				kingX = j;
				kingY = i;
			}
		}
	}
	kingX += 97;
	kingY += 1;
}

void Chess2::check() {
	/*loops through the entire board and runs movePiece function on every piece to every single square to see
	if any valid moves exist that could capture the king. The move var has been turned off at the start of this function
	to let the computer know that I don't want to actually move any pieces right now. The move var is turned back on at 
	the	end	*/ 
	//101,1 = e,1   
	cout << "King is at " << kingX;
	cout << "," << kingY << endl;
	move = false;
	for (int i = 97; i <= 104; i++) {
		for (int j = 1; j <= 8; j++) {
			movePiece(i, j, kingX, kingY);
		}
	}
	if (goodMove) {
		changeTurn();
		goodMove = false;
	}
	move = true;
	if (kingCheck) {
		cout << "The opponent's king is in check\n";
		//saveKing();
	}	
}

void Chess2::saveKing() {
	while (true) {
		cout << "The opponent's king is in check";
		int y, y2;
		char x, x2;
		cout << "Select a piece to move (letter first): ";
		cin >> x >> y;
		cout << "Select a square to move it to (letter first): ";
		cin >> x2 >> y2;
		movePiece(x, y, x2, y2);
		if (!kingCheck) {
			break;
		}
	}
}


void Chess2::pawnMove(int y, int x, int y2, int x2) {
	//restricts pawns from moving too many spaces
	if (abs(x - x2) >= 2 || (abs(x2 - x) == 1 && chessBoard[y2][x2] == "")) {
		if (move)
		cout << "Violation- a pawn cannot move like that\n";
	}
	//allows pawns to move one space or two spaces if first move
	else if ((y - y2) == 2 && y == 6 || (y2 - y) == 2 && y == 1 || abs(y - y2) == 1 && chessBoard[y2][x2] == "") {
		if (move) {
			chessBoard[y2][x2] = chessBoard[y][x];
			chessBoard[y][x] = "";
			goodMove = true;
		}
	}
	//allows the pawns to capture pieces on the diagonal move
	else if (abs(x2 - x) == 1 && abs(y - y2) == 1 && (chessBoard[y2][x2] != "")) {
		if (move) {
			chessBoard[y2][x2] = chessBoard[y][x];
			chessBoard[y][x] = "";	
			kingCheck = false;
			goodMove = true;
		}
		else {
			if (lowerCase) {
				if (chessBoard[y2][x2] == "KING") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
			else {
				if (chessBoard[y2][x2] == "king") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
		}
	}
	else {
		if (move)
		cout << "Violation- a pawn cannot move like that\n";
	}
}

void Chess2::rookMove(int x, int y, int x2, int y2) {
	//check that rook is moving on clear path
	bool valid = clearPathRook(x, y, x2, y2);
	if (valid) {
		//rook can only move in straight lines
		if (y == y2 || x == x2) {
			//if move variable is true, then rook is being moved
			if (move) {
				chessBoard[x2][y2] = chessBoard[x][y];
				chessBoard[x][y] = "";
				kingCheck = false;
				goodMove = true;
			}
			//if move variable is false, then we're just seeing if king is in check
			else {
				if (chessBoard[x2][y2] == "KING") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
		}
		else {
			if (move)
			cout << "Violation- a rook cannot move like that";
		}
	}
	else {
			if (move)
				cout << "Move path was not open\n";
		}
	}

bool Chess2::clearPathRook(int x, int y, int x2, int y2) {
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



void Chess2::knightMove(int x, int y, int x2, int y2) {
	//restricts knight's movement to L pattern
	if (abs(y - y2) == 2 && abs(x2 - x) == 1) {
		if (move) {
			chessBoard[x2][y2] = chessBoard[x][y];
			chessBoard[x][y] = "";
			kingCheck = false;
			goodMove = true;
		}
		else {
			if (lowerCase) {
				if (chessBoard[x2][y2] == "KING") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
			else {
				if (chessBoard[x2][y2] == "king") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}			
			}
		}
	} 
	//restricts knight movement to L pattern
	else if (abs(y - y2) == 1 && abs(x2 - x) == 2) {
		//if move variable is true, then knight is being moved
		if (move) {
			chessBoard[x2][y2] = chessBoard[x][y];
			chessBoard[x][y] = "";
			kingCheck = false;
			goodMove = true;
	}
		//if move variable is false, then we're seeing if king is in check
		else {
			if (lowerCase) {
				if (chessBoard[x2][y2] == "KING") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
			else {
				if (chessBoard[x2][y2] == "king") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
		}
	} else {
		if (move) {
			cout << "Violation, a knight cannot move like that\n";
		}
	}
}


void Chess2::bishopMove(int x, int y, int x2, int y2) {
	//restricts bishop's movement to diagonal only
	if (abs(x - x2) == abs(y2 - y)) {
		//checks that bishop is taking a clear path
		bool valid = clearPathBishop(x, y, x2, y2);
		//if move var is true, then we're trying to move bishop
		if (valid && move) {
			chessBoard[x2][y2] = chessBoard[x][y];
			chessBoard[x][y] = "";
			kingCheck = false;
			goodMove = true;
		}
		//if move var is false, then we're seeing if king is in check
		else if (valid) {
			if (lowerCase) {
				if (chessBoard[x2][y2] == "KING") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
			else {
				if (chessBoard[x2][y2] == "king") {
					kingCheck = true;
				}
				else {
					kingCheck = false;
				}
			}
		}
		else if (move) {
			cout << "Move path was not open\n";
		}
	}
	else {
		if (move)
		cout << "Violation- a bishop cannot move like that\n";
	}
}

bool Chess2::clearPathBishop(int x, int y, int x2, int y2) {
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

void Chess2::queenMove(int x, int y, int x2, int y2) {
	//restricting queen's movement to that of rook and bishop combined
	if (abs(x - x2) == abs(y2 - y) || (x == x2) || (y == y2)) {
		//checks bishop's clear path function
		bool validB = clearPathBishop(x, y, x2, y2);
		if (validB) {
			//checks rook's clear path function
			bool valid = clearPathRook(x, y, x2, y2);
			if (valid) {
				//ensures clear path is valid if queen is only moving one space
				if (abs((y - y2) == 1 || abs(x2 - x) == 1)) {
					valid = true;
				}
				//if move var is true, then we're trying to move the queen
				if (valid && move) {
					chessBoard[x2][y2] = chessBoard[x][y];
					chessBoard[x][y] = "";
					kingCheck = false;
					goodMove = true;
				}
				//if move var is false, then we're seeing if king is in check
				else if (valid) {
					if (lowerCase) {
						if (chessBoard[x2][y2] == "KING") {
							kingCheck = true;
						}
						else {
							kingCheck = false;
						}
					}
					else {
						if (chessBoard[x2][y2] == "king") {
							kingCheck = true;
						}
						else {
							kingCheck = false;
						}
					}
				}
			}
			else {
				if (move)
					cout << "Move path was not open\n";
			}
		}
		else {
			if (move)
			cout << "Move path was not open\n";
		}
	}
	else {
		if (move)
		cout << "Violation- a queen cannot move like that\n";
	}
}

void Chess2::kingMove(int x, int y, int x2, int y2) {
	//restricts king to move only space at a time
	if ((y - y2) <= 1 && (x2 - x) <= 1 && (y2 - y) <= 1 && (x - x2) <= 1) {
		if (move) {
			chessBoard[x2][y2] = chessBoard[x][y];
			chessBoard[x][y] = "";
			goodMove = true;
		}
	}
	else {
		if (move)
		cout << "Violation- a king cannot move like that\n";
	}
}




