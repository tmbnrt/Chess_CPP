#include "Knight.h"

Knight::Knight() {
	this->points = 3;
	this->countMoves = 0;
}

char Knight::getDesignation() const {
	return designation;
}

void Knight::checkMoves(std::vector<std::vector<Character*>> board) {
	this->moves.clear();
	this->kills.clear();

	getPlayersPositions(board);
	int enemy = 1;
	if (player == 1)
		enemy = 2;
	
	/*
	// pos col
	std::vector<int> newPos = std::vector<int>{ position[0], position[1] + 1 };
	if (newPos[1] < 8) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && action.noChess(newPos))
			action.addKill(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && action.noChess(newPos))
			action.addMove(newPos);
	}
	*/
}

Knight::~Knight() {}
