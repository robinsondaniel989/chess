#include "Chess2.h"
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool Chess2::validMove(string yourPiece, string destination, bool move, bool lowerCase) {
	if (yourPiece == "" && move) {
		cout << "You must select a piece\n";
		return false;
	}
	else {
		if ((isupper(yourPiece[0]) && move && lowerCase) || (islower(yourPiece[0]) && move && !lowerCase)) {
			cout << "You cannot move an opponent's piece, try again.\n";
			return false;
		}
		else if ((islower(destination[0]) && move && lowerCase) || (isupper(destination[0]) && move && !lowerCase)) {
			cout << "You cannot move one of your pieces to a space that contains one of your pieces, try again.\n";
			return false;
		}
		else {
			return true;
		}
	}
}



