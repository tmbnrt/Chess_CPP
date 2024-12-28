#include "King.h"

King::King() {
	this->initMove = true;
}

char King::getDesignation() const {
	return Character::designation;
}

King::~King() { }
