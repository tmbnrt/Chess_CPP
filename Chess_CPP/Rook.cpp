#include "Rook.h"

Rook::Rook() {
	this->points = 5;
	this->countMoves = 0;
}

char Rook::getDesignation() const {
	return designation;
}

void Rook::checkMoves(std::vector<std::vector<Character*>> board) {
	this->moves.clear();
	this->kills.clear();

	getPlayersPositions(board);
	int enemy = 1;
	if (player == 1)
		enemy = 2;
	
	// pos col
	for (int i = 1; i < 8; i++)	{
		std::vector<int> newPos = std::vector<int> { position[0], position[1] + i };
		if (newPos[1] < 8) {
			if (playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy)
				this->moves.push_back(newPos);
			if (playersPositions[newPos[0]][newPos[1]] == enemy) {
				this->kills.push_back(newPos);
				break;
			}
			if (playersPositions[newPos[0]][newPos[1]] == player)
				break;
		}
	}

	// neg col
	for (int i = 1; i < 8; i++) {
		std::vector<int> newPos = std::vector<int>{ position[0], position[1] - i };
		if (newPos[1] >= 0) {
			if (playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy)
				this->moves.push_back(newPos);
			if (playersPositions[newPos[0]][newPos[1]] == enemy) {
				this->kills.push_back(newPos);
				break;
			}
			if (playersPositions[newPos[0]][newPos[1]] == player)
				break;
		}
	}

	// pos row
	for (int i = 1; i < 8; i++) {
		std::vector<int> newPos = std::vector<int>{ position[0] + i, position[1]};
		if (newPos[1] < 8) {
			if (playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy)
				this->moves.push_back(newPos);
			if (playersPositions[newPos[0]][newPos[1]] == enemy) {
				this->kills.push_back(newPos);
				break;
			}
			if (playersPositions[newPos[0]][newPos[1]] == player)
				break;
		}
	}

	// neg row
	for (int i = 1; i < 8; i++) {
		std::vector<int> newPos = std::vector<int>{ position[0] - i, position[1] };
		if (newPos[1] >= 0) {
			if (playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy)
				this->moves.push_back(newPos);
			if (playersPositions[newPos[0]][newPos[1]] == enemy) {
				this->kills.push_back(newPos);
				break;
			}
			if (playersPositions[newPos[0]][newPos[1]] == player)
				break;
		}
	}
}

Rook::~Rook() {}
