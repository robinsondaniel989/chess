#include "Queen.h"

Queen::Queen(int _id) {
	name = "queen";
	id = name.at(0) + to_string(_id);
}

string Queen::getName() {
	return name;
}

void Queen::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}
