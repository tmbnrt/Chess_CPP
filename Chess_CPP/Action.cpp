#include "Action.h"

Action::Action() {
	this->movesPlayer_1 = std::vector<std::vector<int>>();
}

void Action::printBoard(std::vector<std::vector<Character*>> board) {
	for (int i = 0; i < board.size(); i++) {
		std::cout << (i + 1) << "| ";
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] != nullptr)
				std::cout << " " << board[i][j]->getDesignation() << " ";
			else
				std::cout << " 0 ";
		}

		std::cout << std::endl;
	}

	std::cout << "    ______________________" << std::endl;
	std::cout << "    A  B  C  D  E  F  G  H" << std::endl;
	std::cout << std::endl;
}

std::vector<std::vector<int>> Action::getMoves(int player) {
	if (player == 1)
		return movesPlayer_1;
	else
		return movesPlayer_2;
}

void Action::updateMoves(std::vector<std::vector<int>> moves, std::vector<std::vector<int>> kills, int player) {
	std::vector<std::vector<int>> allMoves = std::vector<std::vector<int>>();
	allMoves.insert(allMoves.end(), moves.begin(), moves.end());
	allMoves.insert(allMoves.end(), kills.begin(), kills.end());
	if (player == 1)
		this->movesPlayer_1 = allMoves;
	else
		this->movesPlayer_2 = allMoves;
}

Action::~Action(){}