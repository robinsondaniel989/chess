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
