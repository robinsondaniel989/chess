#include <vector>
#include "Chess2.h"
#include <iostream>
#include <string>
#include "Pawn.h"
#include "Knight.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
using namespace std;

Pawn pawn(1);
Rook rook(1);
Knight knight(1);
Bishop bishop(1);
Queen queen(1);
King king(1);

void printBoard(vector<vector<string>> chessBoard) {
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

vector<vector<string>> createBoard() {
	vector<vector<string>> chessBoard(8, vector<string>(8));

	for (int i = 0; i < 8; i++) {
		chessBoard[6][i] = pawn.getName();
	}
	for (int i = 0; i < 8; i++) {
		pawn.capName();
		chessBoard[1][i] = pawn.getName();
	}
	int x = 1;
	for (int i = 0; i < 2; i++) {
		chessBoard[7][x] = knight.getName();
		x += 5;
	}
	x = 1;
	for (int i = 0; i < 2; i++) {
		knight.capName();
		chessBoard[0][x] = knight.getName();
		x += 5;
	}
	x = 0;
	for (int i = 0; i < 2; i++) {
		chessBoard[7][x] = rook.getName();
		x += 7;
	}
	x = 0;
	for (int i = 0; i < 2; i++) {
		rook.capName();
		chessBoard[0][x] = rook.getName();
		x += 7;
	}
	x = 2;
	for (int i = 0; i < 2; i++) {
		chessBoard[7][x] = bishop.getName();
		x += 3;
	}
	x = 2;
	for (int i = 0; i < 2; i++) {
		bishop.capName();
		chessBoard[0][x] = bishop.getName();
		x += 3;
	}
	chessBoard[7][3] = queen.getName();
	queen.capName();
	chessBoard[0][3] = queen.getName();
	chessBoard[7][4] = king.getName();
	king.capName();
	chessBoard[0][4] = king.getName();

	return chessBoard;
}

int check(vector<vector<string>> chessBoard, vector<int> kingCoor, bool lowerCase) {
	/*loops through the entire board and runs movePiece function on every piece to every single square to see
	if any valid moves exist that could capture the king. The move var has been turned off at the start of this function
	to let the computer know that I don't want to actually move any pieces right now */
	int check;
	int check1 = 0;
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {			
		if (chessBoard[i][j] == "pawn") {
				check = pawn.move(i, j, kingCoor[0], kingCoor[1], chessBoard, false, lowerCase);
				if (check == 2) {
					check1 += 1;
				}
			}
		else if (chessBoard[i][j] == "knight") {
				check = knight.move(i, j, kingCoor[0], kingCoor[1], chessBoard, false);
				if (check == 2) {
					check1 += 1;
				}
			}
		else if (chessBoard[i][j] == "bishop") {
				check = bishop.move(i, j, kingCoor[0], kingCoor[1], chessBoard, false);
				if (check == 2) {
					check1 += 1;
				}
			}
		else if (chessBoard[i][j] == "rook") {
				check = rook.move(i, j, kingCoor[0], kingCoor[1], chessBoard, false);
				if (check == 2) {
					check1 += 1;
				}
			}
		else if (chessBoard[i][j] == "queen") {
				check = queen.move(i, j, kingCoor[0], kingCoor[1], chessBoard, false);
				if (check != 0) {
					check1 += 1;
				}
			}
		else if (chessBoard[i][j] == "king") {
				check = king.move(i, j, kingCoor[0], kingCoor[1], chessBoard, false);
				if (check == 2) {
					check1 += 1;
				}
			}			
		}
	}
	return check1;
}

vector<int> findKing(vector<vector<string>> chessBoard) {
	int kingX = 0;
	int kingY = 0;
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (chessBoard[i][j] == "KING") {
				kingX = i;
				kingY = j;
			}
		}
	}
	vector<int> kingCoor = { kingX, kingY };
	return kingCoor;
}



int main(void) {

	vector<vector<string>> chessBoard = createBoard();	
	Chess2 chess;
	int counter = 0;	
	bool lowerCase = true;
	int result = 0;
	do {
		printBoard(chessBoard);
		int y, y2;
		char x, x2;
		cout << "Select a piece to move (letter first): ";
		cin >> x >> y;
		cout << "Select a square to move it to (letter first): ";
		cin >> x2 >> y2;
		y--; y2--;
		x2 -= 97; x -= 97;
		string yourPiece = chessBoard[y][x];
		string destination = chessBoard[y2][x2];
		cout << yourPiece;
		bool valid = chess.validMove(yourPiece, destination, true, lowerCase);
		if (valid) {
			cout << "valid";
			if (yourPiece == "pawn" || "PAWN") {
				result = pawn.move(y, x, y2, x2, chessBoard, true, lowerCase);
			}
			else if (yourPiece == "knight" || "KNIGHT") {
				result = knight.move(y, x, y2, x2, chessBoard, true);
			}
			else if (yourPiece == "bishop" || "BISHOP") {
				result = bishop.move(y, x, y2, x2, chessBoard, true);
			}
			else if (yourPiece == "rook" || "ROOK") {
				result = rook.move(y, x, y2, x2, chessBoard, true);
			}
			else if (yourPiece == "queen" || "QUEEN") {
				result = queen.move(y, x, y2, x2, chessBoard, true);
			}
			else if (yourPiece == "king" || "KING") {
				result = king.move(y, x, y2, x2, chessBoard, true);
			}



			if (result == 1) {
				chessBoard[y2][x2] = chessBoard[y][x];
				chessBoard[y][x] = "";
				cout << "good move\n";
				lowerCase = !lowerCase;
			}
			else {
				cout << "move was no good\n";
			}
			vector<int> kingCoor = findKing(chessBoard);
			int check1 = check(chessBoard, kingCoor, lowerCase);
			cout << check1;
			if (check1 == 0) {
				cout << "king not in check\n";
			}
			else {
				cout << "KING IN CHECK\n";
			}
		}
		else {
			cout << "Move was not valid\n";
		}			
		
	} while (counter < 40);	

	return 0;
}

