#include "King.h"

King::King(int _id) {
	name = "king";
	id = name.at(0) + to_string(_id);
}

string King::getName() {
	return name;
}

void King::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}
