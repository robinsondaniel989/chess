#include "Knight.h"


Knight::Knight(int _id) {
	name = "knight";
	id = name.at(0) + to_string(_id);
}

string Knight::getName() {
	return name;
}

void Knight::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}

