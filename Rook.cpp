#include "Rook.h"

Rook::Rook(int _id) {
	name = "rook";
	id = name.at(0) + to_string(_id);
}

string Rook::getName() {
	return name;
}

void Rook::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

