#include "Bishop.h"

Bishop::Bishop() {
	this->points = 3;
}

char Bishop::getDesignation() const {
	return Character::designation;
}

Bishop::~Bishop() {}
