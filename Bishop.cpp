#include "Bishop.h"

Bishop::Bishop(int _id) {
	name = "bishop";
	id = name.at(0) + to_string(_id);
}

string Bishop::getName() {
	return name;
}

void Bishop::capName() {
	for (auto& x : name)
		x = toupper(x);
	id[0] = toupper(id[0]);
}
