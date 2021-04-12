#include <vector>
#include "Chess2.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	Chess2 game;
	int counter = 0;
	game.printBoard();

	do {
		int y, y2;
		char x, x2;
		cout << "Select a piece to move (letter first): ";		
		cin >> x >> y;
		cout << "Select a square to move it to (letter first): ";
		cin >> x2 >> y2;
		game.movePiece(x, y, x2, y2);
		game.printBoard();
		game.findKing();
		game.check();
		//game.saveKing();
		
		counter++;
		bool turn = game.getCase();
	} while (counter < 40);

	return 0;
}