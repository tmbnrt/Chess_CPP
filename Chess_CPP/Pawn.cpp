#include "Pawn.h"

Pawn::Pawn() {
	this->points = 1;
	this->countMoves = 0;
}

char Pawn::getDesignation() const {
	return designation;
}

Action Pawn::checkMoves(std::vector<std::vector<Character*>> board) {
	Action action = Action();

	getPlayersPositions(board);
	int enemy = 1;
	if (player == 1)
		enemy = 2;

	// pos dir
	if (player == 2) {
		std::vector<int> newPos = std::vector<int>{ position[0] + 1, position[1] };
		if (newPos[0] < 8 && playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy) {
			action.addMove(newPos);
		}
		if (countMoves == 0 && playersPositions[newPos[0]][newPos[1]] != enemy && playersPositions[newPos[0]][newPos[1]] != player) {
			std::vector<int> newPos = std::vector<int>{ position[0] + 2, position[1] };
			if (newPos[1] < 8 && playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy) {
				action.addMove(newPos);
			}
		}

		// Kill moves
		std::vector<int> killPos1 = std::vector<int>{ position[0] + 1, position[1] + 1 };
		std::vector<int> killPos2 = std::vector<int>{ position[0] + 1, position[1] - 1 };
		
		if (killPos1[0] < 8 && killPos1[1] < 8) {
			if (playersPositions[killPos1[0]][killPos1[1]] == enemy)
				action.addKill(killPos1);
			// En passante
			if (playersPositions[position[0]][position[1] + 1] == enemy) {
				if (position[0] == 4 && board[position[0]][position[1] + 1]->getPoints() == 1 && board[position[0]][position[1] + 1]->numberOfMoves() == 1 &&
					playersPositions[killPos1[0]][killPos1[1]] != player && playersPositions[killPos1[0]][killPos1[1]] != enemy)
					action.addKill(killPos1);
			}			
		}
		
		if (killPos2[0] < 8 && killPos2[1] >= 0) {
			if (playersPositions[killPos2[0]][killPos2[1]] == enemy)
				action.addKill(killPos2);

			if (playersPositions[position[0]][position[1] - 1] == enemy) {
				if (position[0] == 4 && board[position[0]][position[1] - 1]->getPoints() == 1 && board[position[0]][position[1] - 1]->numberOfMoves() == 1 &&
					playersPositions[killPos2[0]][killPos2[1]] != player && playersPositions[killPos2[0]][killPos2[1]] != enemy)
					action.addKill(killPos2);
			}			
		}
	}
	else {
		std::vector<int> newPos = std::vector<int>{ position[0] - 1, position[1] };
		if (newPos[0] >= 0 && playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy) {
			action.addMove(newPos);
		}
		if (countMoves == 0 && playersPositions[newPos[0]][newPos[1]] != enemy && playersPositions[newPos[0]][newPos[1]] != player) {
			std::vector<int> newPos = std::vector<int>{ position[0] - 2, position[1] };
			if (newPos[1] >= 0 && playersPositions[newPos[0]][newPos[1]] != player && playersPositions[newPos[0]][newPos[1]] != enemy) {
				action.addMove(newPos);
			}
		}

		// Kill moves
		std::vector<int> killPos1 = std::vector<int>{ position[0] - 1, position[1] + 1 };
		std::vector<int> killPos2 = std::vector<int>{ position[0] - 1, position[1] - 1 };

		if (killPos1[0] >= 0 && killPos1[1] < 8) {
			if (playersPositions[killPos1[0]][killPos1[1]] == enemy)
				action.addKill(killPos1);
			// En passante
			if (playersPositions[position[0]][position[1] + 1] == enemy) {
				if (position[0] == 3 && board[position[0]][position[1] + 1]->getPoints() == 1 &&
					playersPositions[killPos1[0]][killPos1[1]] != player && playersPositions[killPos1[0]][killPos1[1]] != enemy)
					action.addKill(killPos1);
			}			
		}

		if (killPos2[0] >= 0 && killPos2[1] >= 0) {
			if (playersPositions[killPos2[0]][killPos2[1]] == enemy)
				action.addKill(killPos2);

			if (playersPositions[position[0]][position[1] - 1] == enemy) {
				if (position[0] == 3 && board[position[0]][position[1] - 1]->getPoints() == 1 &&
					playersPositions[killPos2[0]][killPos2[1]] != player && playersPositions[killPos2[0]][killPos2[1]] != enemy)
					action.addKill(killPos2);
			}			
		}
	}

	return action;
}

Pawn::~Pawn() {}
