#include <vector>
#include "Chess.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {

	Chess game;
	int counter = 0;
	vector<vector<Chess>> chessBoard = game.newGame();
	game.printBoard(chessBoard);
	do {
		chessBoard = game.movePiece(chessBoard, 1);
		game.printBoard(chessBoard);
		counter++;
	} while (counter <= 10);

	return 0;
}