#include "Queen.h"

Queen::Queen() {
	this->points = 9;
}

char Queen::getDesignation() const {
	return Character::designation;
}

Queen::~Queen() {}
