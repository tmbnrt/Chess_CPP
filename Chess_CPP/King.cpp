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

std::vector<std::vector<Character*>> copyBoard(std::vector<std::vector<Character*>> input) {
	std::vector<std::vector<Character*>> blueprint(8, std::vector<Character*>(8));
	/*
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < input[0].size(); j++) {
			if (input[i][j])
				blueprint[i][j] = input[i][j]->getCopy();
			else
				blueprint[i][j] = nullptr;
		}
	}
	...
	*/
	return blueprint;	
}

// Check for the possible input move if king is still in chess
bool King::rescued(std::vector<std::vector<Character*>> board, int act_row, int act_col, std::vector<int> to) {	
	// Create test copy of board (pointer to new address)
	//std::vector<std::vector<Character*>> copy_board;
	/*for (const auto& board_col : board) {
		std::vector<Character*> copy_board_col;
		for (const auto& ptr : board_col) {
			// Reservate new memory and copy value
			if (ptr)
				copy_board_col.push_back(new Character(*ptr));
			else
				copy_board_col.push_back(nullptr);
		}

		this->copy_board.push_back(copy_board_col);
	}*/
	this->copy_board = copyBoard(board);

	this->copy_board = copy_board[act_row][act_col]->move(copy_board, std::vector<int> { to[0], to[1] });

	//board[position[0]][position[1]]->isChess();
	this->copy_board[position[0]][position[1]]->checkMoves(copy_board, false, false);
	if (!copy_board[position[0]][position[1]]->isChess()) {		
		clearMemory();
		return true;
	}

	clearMemory();
	return false;
}

void King::checkForRescue(std::vector<std::vector<Character*>> board) {

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == nullptr)
				continue;
			if (board[i][j]->getPlayer() != player || board[i][j]->getPoints() > 10)
				continue;

			std::vector<std::vector<int>> moves = board[i][j]->getMoves();
			std::vector<std::vector<int>> kills = board[i][j]->getKills();
			moves.insert(moves.end(), moves.begin(), moves.end());
			
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
}

void King::checkMoves(std::vector<std::vector<Character*>> board, bool friendlyFire, bool checkRescue) {
	this->moves.clear();
	this->kills.clear();
	this->rescueMovesFrom.clear();
	this->rescueMovesTo.clear();

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
