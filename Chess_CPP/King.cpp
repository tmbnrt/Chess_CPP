#include "King.h"

King::King() {
	this->points = 1000;
	this->countMoves = 0;
	this->rescueMovesFrom = std::vector<std::vector<int>>();
	this->rescueMovesTo = std::vector<std::vector<int>>();
	DangerZone dangerZone = DangerZone();
}

//King* King::getCopy() const {
//	return new King(*this);
//}

void King::clearMemory() {
	for (int i = 0; i < copy_board.size(); i++) {
		for (int j = 0; j < copy_board[0].size(); j++) {
			if (copy_board[i][j])
				delete this->copy_board[i][j];
			this->copy_board[i][j] = nullptr;
		}
	}
}

std::vector<std::vector<Character*>> King::copyBoard(std::vector<std::vector<Character*>> input) {
	std::vector<std::vector<Character*>> copy(8, std::vector<Character*>(8));
	/*
	Player copyPlayer_white = Player();
	copyPlayer_white.assign("copy_1", 1);
	Player copyPlayer_black = Player();
	copyPlayer_black.assign("copy_2", 2);

	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[0].size(); j++) {
			if (input[i][j]) {
				if (input[i][j]->getPlayer() == 1) {
					copy = copyPlayer_white.copy_putChars(copy, i, j, input[i][j]);
				}
			}			
			
			if (input[i][j])
				blueprint[i][j] = input[i][j]->getCopy();
			else
				blueprint[i][j] = nullptr;
			
		}
	}
	*/
	return copy;
}

// Check for the possible input move if king is still in chess
bool King::rescued(std::vector<std::vector<Character*>> board, int act_row, int act_col, std::vector<int> to) {
	
	board = board[act_row][act_col]->move(board, std::vector<int> { to[0], to[1] });
	board[position[0]][position[1]]->checkMoves(board, false, false);
	
	if (!board[position[0]][position[1]]->isChess()) {
		board = board[position[0]][position[1]]->reverse(board);
		return true;
	}

	board = board[position[0]][position[1]]->reverse(board);
	return false;
}

void King::checkForRescue(std::vector<std::vector<Character*>> board) {
	// TEST
	this->rescueMovesFrom.clear();
	this->rescueMovesTo.clear();
	// TEST

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == nullptr)
				continue;
			if (board[i][j]->getPlayer() != player || board[i][j]->getPoints() > 10)
				continue;
			
			// TEST
			board[i][j]->checkMoves(board);
			// TEST

			std::vector<std::vector<int>> moves = board[i][j]->getMoves();
			std::vector<std::vector<int>> kills = board[i][j]->getKills();
			moves.insert(moves.end(), kills.begin(), kills.end());
			
			for (int k = 0; k < moves.size(); k++) {
				std::vector<int> pos = std::vector<int>{ i, j };
				bool kingSaved = rescued(board, i, j, moves[k]);
				if (kingSaved) {
					this->rescueMovesFrom.push_back(pos);
					this->rescueMovesTo.push_back(moves[k]);
				}
			}			

			board[i][j]->delMoves();
			board[i][j]->delKills();
		}
	}

	this->chess = true;
}

void King::checkMoves(std::vector<std::vector<Character*>> board, bool friendlyFire, bool checkRescue) {
	this->moves.clear();
	this->kills.clear();
	/*this->rescueMovesFrom.clear();
	this->rescueMovesTo.clear();*/

	dangerZone.createDangerZone(board, player);

	getPlayersPositions(board);
	int enemy = 1;
	if (player == 1)
		enemy = 2;

	std::vector<int> newPos{ position[0], position[1] };

	// Check chess (actual position)
	if (!dangerZone.noChess(newPos)) {
			this->chess = true;
		if (checkRescue)
			checkForRescue(board);
	}		
	else
		this->chess = false;		

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

std::vector<std::vector<int>> King::getRescueMovesFrom() const {
	return rescueMovesFrom;
}

std::vector<std::vector<int>> King::getRescueMovesTo() const {
	return rescueMovesTo;
}

bool King::isChess() const {
	return chess;
}

char King::getDesignation() const {
	return designation;
}

King::~King() {}
