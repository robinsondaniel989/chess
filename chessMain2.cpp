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
		Pawn pawn(i + 1);
		chessBoard[6][i] = pawn.getName();
	}
	for (int i = 0; i < 8; i++) {
		Pawn pawn(i + 1);
		pawn.capName();
		chessBoard[1][i] = pawn.getName();
	}
	int x = 1;
	for (int i = 0; i < 2; i++) {
		Knight knight(i + 1);
		chessBoard[7][x] = knight.getName();
		x += 5;
	}
	x = 1;
	for (int i = 0; i < 2; i++) {
		Knight knight(i + 1);
		knight.capName();
		chessBoard[0][x] = knight.getName();
		x += 5;
	}
	x = 0;
	for (int i = 0; i < 2; i++) {
		Rook rook(i + 1);
		chessBoard[7][x] = rook.getName();
		x += 7;
	}
	x = 0;
	for (int i = 0; i < 2; i++) {
		Rook rook(i + 1);
		rook.capName();
		chessBoard[0][x] = rook.getName();
		x += 7;
	}
	x = 2;
	for (int i = 0; i < 2; i++) {
		Bishop bishop(i + 1);
		chessBoard[7][x] = bishop.getName();
		x += 3;
	}
	x = 2;
	for (int i = 0; i < 2; i++) {
		Bishop bishop(i + 1);
		bishop.capName();
		chessBoard[0][x] = bishop.getName();
		x += 3;
	}
	Queen queen(1);
	chessBoard[7][3] = queen.getName();
	Queen queen2(2);
	queen2.capName();
	chessBoard[0][3] = queen2.getName();
	King king(1);
	chessBoard[7][4] = king.getName();
	King king2(2);
	king2.capName();
	chessBoard[0][4] = king2.getName();

	return chessBoard;
}



int main(void) {

	vector<vector<string>> chessBoard = createBoard();	
	Chess2 chess;
	int counter = 0;
	bool move = true;
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
		bool valid = chess.validMove(yourPiece, destination, move, lowerCase);
		if (valid) {
			cout << "valid";
		}
		if (yourPiece == "pawn") {
			Pawn pawn(1);
			result = pawn.move(y, x, y2, x2, chessBoard, move);
		}
		else if (yourPiece == "knight") {
			Knight knight(1);
			result = knight.move(y, x, y2, x2, chessBoard, move);
		}
		else if (yourPiece == "bishop") {
			Bishop bishop(1);
			result = bishop.move(y, x, y2, x2, chessBoard, move);
		}
		else if (yourPiece == "queen") {
			Queen queen(1);
			result = queen.move(y, x, y2, x2, chessBoard, move);
		}
		else if (yourPiece == "king") {
			King king(1);
			result = king.move(y, x, y2, x2, chessBoard, move);
		}

		if (result == 1) {
			chessBoard[y2][x2] = chessBoard[y][x];
			chessBoard[y][x] = "";		
			cout << "good move\n";
		}
		else if (result == 2) {
			chessBoard[y2][x2] = chessBoard[y][x];
			chessBoard[y][x] = "";
			cout << "king is in check\n";
		}
		else {
			cout << "move was no good\n";
		}


	} while (counter < 40);
	//Chess2 game;
	//int counter = 0;
	//game.printBoard();

	//do {
	//	int y, y2;
	//	char x, x2;
	//	cout << "Select a piece to move (letter first): ";		
	//	cin >> x >> y;
	//	cout << "Select a square to move it to (letter first): ";
	//	cin >> x2 >> y2;
	//	game.movePiece(x, y, x2, y2);
	//	game.printBoard();
	//	game.findKing();
	//	game.check();
	//	//game.saveKing();
	//	
	//	counter++;
	//	bool turn = game.getCase();
	//} while (counter < 40);

	return 0;
}

