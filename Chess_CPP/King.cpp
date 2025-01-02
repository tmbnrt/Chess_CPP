#include "King.h"

King::King() {
	this->points = 1000;
	this->countMoves = 0;
	DangerZone dangerZone = DangerZone();
}

void King::checkMoves(std::vector<std::vector<Character*>> board, bool friendlyFire) {
	this->moves.clear();
	this->kills.clear();

	dangerZone.createDangerZone(board, player);

	getPlayersPositions(board);
	int enemy = 1;
	if (player == 1)
		enemy = 2;

	std::vector<int> newPos;

	// pos col
	newPos = std::vector<int>{ position[0], position[1] + 1 };
	if (newPos[1] < 8) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// neg col
	newPos = std::vector<int>{ position[0], position[1] - 1 };
	if (newPos[1] >= 0) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// pos row
	newPos = std::vector<int>{ position[0] + 1, position[1] };
	if (newPos[0] < 8) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// neg row
	newPos = std::vector<int>{ position[0] - 1, position[1] };
	if (newPos[0] >= 0) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// SE
	newPos = std::vector<int>{ position[0] + 1, position[1] + 1 };
	if (newPos[0] < 8 && newPos[1] < 8) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// NE
	newPos = std::vector<int>{ position[0] - 1, position[1] + 1 };
	if (newPos[0] >= 0 && newPos[1] < 8) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// SW
	newPos = std::vector<int>{ position[0] + 1, position[1] - 1 };
	if (newPos[0] < 8 && newPos[1] >= 0) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}

	// NW
	newPos = std::vector<int>{ position[0] - 1, position[1] - 1 };
	if (newPos[0] >= 0 && newPos[1] >= 0) {
		if (playersPositions[newPos[0]][newPos[1]] == enemy && dangerZone.noChess(newPos))
			this->kills.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] != player && dangerZone.noChess(newPos))
			this->moves.push_back(newPos);
		else if (playersPositions[newPos[0]][newPos[1]] == player && friendlyFire)
			this->moves.push_back(newPos);
	}
}

char King::getDesignation() const {
	return designation;
}

King::~King() {}
