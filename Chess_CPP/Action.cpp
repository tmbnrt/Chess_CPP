#include "Action.h"

Action::Action() {
	this->moves = std::vector<std::vector<int>>();
	this->kills = std::vector<std::vector<int>>();
}

void Action::addMove(std::vector<int> move) {
	this->moves.push_back(move);
}

void Action::addKill(std::vector<int> kill) {
	this->kills.push_back(kill);
}

Action::~Action() {}
