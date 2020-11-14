#include <vector>
#include "Chess.h"
#include <iostream>
#include <string>
using namespace std;

struct Coordinates {
	int y;
	char x;
} squares[16];

void printCoordinates(Coordinates xy)
{
	cout << xy.x << xy.y << endl;
}

Coordinates createPoints(vector<vector<Chess>> chessBoard, Coordinates xy) {
	for (size_t i = 0; i < 8; i++) {
		for (size_t j = 0; j < 8; j++) {
			if (islower(chessBoard[i][j].getName()[0])) {
				int n = 0;
				squares[n].x = char(j + 97);
				squares[n].y = i + 1;
				cout << "There's a " + chessBoard[i][j].getName() + " at: ";
				printCoordinates(squares[n]);
				n++;
			}
		}
	}
	return xy;
}

int main(void) {

	Chess game;
	Coordinates xy{};
	int counter = 0;
	vector<vector<Chess>> chessBoard = game.newGame();
	game.printBoard(chessBoard);
	xy = createPoints(chessBoard, xy);
	//game.checkMate(chessBoard);
	
	do {
		chessBoard = game.movePiece(chessBoard, 1);
		game.printBoard(chessBoard);
		xy = createPoints(chessBoard, xy);
		counter++;
	} while (counter <= 20);

	return 0;
}