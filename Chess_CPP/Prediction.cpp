#include "Prediction.h"
#include "Python.h"
#include <vector>
#include <iostream>


Prediction::Prediction() {
	std::vector<std::vector<char>> field(8, std::vector<char>(8));
	this->charBoard = field;
	this->moveCounter = 0;
}

void Prediction::updateCharBoard(std::vector<std::vector<Character*>> board) {
	std::vector<std::vector<char>> field(8, std::vector<char>(8));
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] != nullptr)
				this->charBoard[i][j] = board[i][j]->getDesignation();
			else
				this->charBoard[i][j] = '0';
		}
	}
}

void Prediction::inputProcess(std::vector<std::vector<Character*>> board, PlayerMoves playerMoves) {
	updateCharBoard(board);
}

void Prediction::predict() {
	// Initialize Python
	Py_Initialize();
}

std::vector<std::vector<int>> Prediction::getMove() {
	std::vector<std::vector<int>> move(2, std::vector<int>(2));
	move[0] = predicted_from;
	move[1] = predicted_to;

	return move;
}

Prediction::~Prediction() {}