#include "Knight.h"

Knight::Knight() {
	this->points = 3;
}

char Knight::getDesignation() const {
	return Character::designation;
}

Knight::~Knight() {}
