#include "Action.h"

Action::Action() {
	this->movesPlayer_1 = std::vector<std::vector<int>>();
}

std::vector<int> static getCoordsFromStr(std::string inp) {
	std::vector<int> out = std::vector<int>();
	// Char to ASCII
	char col = static_cast<int>(inp[0]) - 65;
	char row = static_cast<int>(inp[1]) - 49;

	out.push_back(row);
	out.push_back(col);

	return out;
}

bool Action::moveAllowed(std::vector<int> from, std::vector<int> to, int player) {
	if (player == 1) {
		for (int i = 0; i < movesPlayer_1.size(); i++) {
			if (movesPlayer_1[i][0][0] == 1)
		}

	}
	

	return true;
}

void Action::moveFromConsole(int player) {
	std::string actual, target;
	std::string input;
	
	bool gotit = false;
	while (!gotit) {
		std::getline(std::cin, input);
		std::istringstream inp_stream(input);

		if (inp_stream >> actual >> target) {		// devide into two strings
			std::string extra;
			if (inp_stream >> extra) {
				std::cout << "Please give only two field coordinates, separated by whitespace.";
			}
			else {
				std::vector<int> from = getCoordsFromStr(actual);
				std::vector<int> to = getCoordsFromStr(target);

				if (from[0] < 0 || from[1] < 0 || to[0] < 0 || to[1] < 0 || from[0] > 7 || from[1] > 7 || to[0] > 7 || to[1] > 7)
					continue;

				if (!moveAllowed(from, to, player))
					continue;

				if (player == 1) {
					this->movesPlayer_1.clear();
					this->movesPlayer_1.push_back(from);
					this->movesPlayer_1.push_back(to);
				}
				else {
					this->movesPlayer_2.clear();
					this->movesPlayer_2.push_back(from);
					this->movesPlayer_2.push_back(to);
				}

				gotit = true;
				std::cout << std::endl;
				std::cout << std::endl;
			}		
		}
		else {
			std::cout << "Please give only two field coordinates, separated by whitespace.";
		}
	}
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