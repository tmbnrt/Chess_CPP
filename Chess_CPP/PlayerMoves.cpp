#include "PlayerMoves.h"

PlayerMoves::PlayerMoves() {
	this->from = std::vector<std::vector<int>>();
	this->to = std::vector<std::vector<int>>();
	this->history_from = std::vector<std::vector<int>>();
	this->history_to = std::vector<std::vector<int>>();
}

void PlayerMoves::addHistory(std::vector<int> actual, std::vector<int> target) {
	this->history_from.push_back(actual);
	this->history_to.push_back(target);
}

void PlayerMoves::checkMoves(std::vector<std::vector<Character*>> board, int player) {
	// del former possibilities
	this->from.clear();
	this->to.clear();

	// Get new possibilities
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] != nullptr) {
				if (board[i][j]->getPlayer() == player) {
					board[i][j]->checkMoves(board);
					std::vector<int> actual = std::vector<int>{ i, j };
					std::vector<std::vector<int>> targets = board[i][j]->getMoves();
					std::vector<std::vector<int>> kills = board[i][j]->getKills();
					targets.insert(targets.end(), kills.begin(), kills.end());
					for (int k = 0; k < targets.size(); k++) {
						this->from.push_back(actual);
						this->to.push_back(targets[k]);
					}
				}				
			}			
		}
	}
}

bool PlayerMoves::checkAllowed(std::vector<int> actual, std::vector<int> target) {
	for (int i = 0; i < from.size(); i++)
		if (from[i][0] == actual[0] && from[i][1] == actual[1] && to[i][0] == target[0] && to[i][1] == target[1])
			return true;
	
	return false;
}

void PlayerMoves::clear() {
	this->from.clear();
	this->to.clear();
}

PlayerMoves::~PlayerMoves(){}