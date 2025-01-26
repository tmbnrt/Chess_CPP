#include "Player.h"

#include<string>

Player::Player() {}

void Player::assign(std::string name, int id) {
	this->name = name;
	this->id = id;
	if (id == 1)
		this->color = "White";
	else
		this->color = "Black";

	initChars();

	// count points
	// ... loop
}

void Player::initChars() {
	if (color == "White") {
		this->king = King();
		//this->king = new King();
		this->king.assign('K', 1);

		this->queens = std::vector<Queen>{ Queen() };
		//this->queens = std::vector<Queen*>{ new Queen() };
		this->queens[0].assign('D', 1);

		this->rooks = std::vector<Rook>{ Rook(), Rook() };
		//this->rooks = std::vector<Rook*>{ new Rook(), new Rook() };
		this->rooks[0].assign('T', 1);
		this->rooks[1].assign('T', 1);

		this->knights = std::vector<Knight>{ Knight(), Knight() };
		//this->knights = std::vector<Knight*>{ new Knight(), new Knight() };
		this->knights[0].assign('S', 1);
		this->knights[1].assign('S', 1);

		this->bishops = std::vector<Bishop>{ Bishop(), Bishop() };
		//this->bishops = std::vector<Bishop*>{ new Bishop(), new Bishop() };
		this->bishops[0].assign('L', 1);
		this->bishops[1].assign('L', 1);

		this->pawns = std::vector<Pawn>{ Pawn(), Pawn(), Pawn(), Pawn(), Pawn(), Pawn(), Pawn(), Pawn() };
		//this->pawns = std::vector<Pawn*>{ new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn() };
		for (int i = 0; i < pawns.size(); i++)
			this->pawns[i].assign('B', 1);
	}
	else {
		this->king = King();
		//this->king = new King();
		this->king.assign('k', 2);

		this->queens = std::vector<Queen> { Queen() };
		//this->queens = std::vector<Queen*> { new Queen() };
		this->queens[0].assign('d', 2);

		this->rooks = std::vector<Rook>{ Rook(), Rook() };
		//this->rooks = std::vector<Rook*>{ new Rook(), new Rook() };
		this->rooks[0].assign('t', 2);
		this->rooks[1].assign('t', 2);

		this->knights = std::vector<Knight>{ Knight(), Knight() };
		//this->knights = std::vector<Knight*>{ new Knight(), new Knight() };
		this->knights[0].assign('s', 2);
		this->knights[1].assign('s', 2);

		this->bishops = std::vector<Bishop>{ Bishop(), Bishop() };
		//this->bishops = std::vector<Bishop*>{ new Bishop(), new Bishop() };
		this->bishops[0].assign('l', 2);
		this->bishops[1].assign('l', 2);

		this->pawns = std::vector<Pawn>{ Pawn(), Pawn(), Pawn(), Pawn(), Pawn(), Pawn(), Pawn(), Pawn() };
		//this->pawns = std::vector<Pawn*>{ new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn(), new Pawn() };
		for (int i = 0; i < pawns.size(); i++)
			this->pawns[i].assign('b', 2);
	}
}

std::vector<std::vector<Character*>> Player::putChars(std::vector<std::vector<Character*>> board) {
	// STRUCTURE
	// [0,0] [0,1] [0,2]
	// [1,0] [1,1] [1,2]
	// [2,0] [2,1] [2,2]
	if (color == "White") {
		king.defPosition(std::vector<int> {7, 4});
		board[7][4] = &king;
		queens[0].defPosition(std::vector<int> {7, 3});
		board[7][3] = &queens[0];
		bishops[0].defPosition(std::vector<int> {7, 2});
		board[7][2] = &bishops[0];
		bishops[1].defPosition(std::vector<int> {7, 5});
		board[7][5] = &bishops[1];
		knights[0].defPosition(std::vector<int> {7, 1});
		board[7][1] = &knights[0];
		knights[1].defPosition(std::vector<int> {7, 6});
		board[7][6] = &knights[1];
		rooks[0].defPosition(std::vector<int> {7, 0});
		board[7][0] = &rooks[0];
		rooks[1].defPosition(std::vector<int> {7, 7});
		board[7][7] = &rooks[1];
		for (int i = 0; i < pawns.size(); i++) {
			pawns[i].defPosition(std::vector<int> {6, i});
			board[6][i] = &pawns[i];
		}			
	}
	else {
		king.defPosition(std::vector<int> {0, 4});
		board[0][4] = &king;
		queens[0].defPosition(std::vector<int> {0, 3});
		board[0][3] = &queens[0];
		bishops[0].defPosition(std::vector<int> {0, 2});
		board[0][2] = &bishops[0];
		bishops[1].defPosition(std::vector<int> {0, 5});
		board[0][5] = &bishops[1];
		knights[0].defPosition(std::vector<int> {0, 1});
		board[0][1] = &knights[0];
		knights[1].defPosition(std::vector<int> {0, 6});
		board[0][6] = &knights[1];
		rooks[0].defPosition(std::vector<int> {0, 0});
		board[0][0] = &rooks[0];
		rooks[1].defPosition(std::vector<int> {0, 7});
		board[0][7] = &rooks[1];		
		for (int i = 0; i < pawns.size(); i++) {
			pawns[i].defPosition(std::vector<int> {1, i});
			board[1][i] = &pawns[i];			
		}
	}

	return board;
}

void Player::delCharVecs() {
	this->rooks.clear();
	this->knights.clear();
	this->knights.clear();
	this->queens.clear();
	this->pawns.clear();
}

/*
std::vector<std::vector<Character*>> Player::copy_putChars(std::vector<std::vector<Character*>> copy, int row, int col, Character* to_copy) {
	
	if (to_copy->getDesignation() == 'B' || to_copy->getDesignation() == 'b') {
		pawns[0].defPosition(std::vector<int> {row, col});
		copy[row][col] = &pawns[0];
	}

	if (to_copy->getDesignation() == 'T' || to_copy->getDesignation() == 't') {
		rooks[0].defPosition(std::vector<int> {row, col});
		copy[row][col] = &rooks[0];
	}

	if (to_copy->getDesignation() == 'S' || to_copy->getDesignation() == 's') {
		knights[0].defPosition(std::vector<int> {row, col});
		copy[row][col] = &knights[0];
	}

	if (to_copy->getDesignation() == 'L' || to_copy->getDesignation() == 'l') {
		bishops[0].defPosition(std::vector<int> {row, col});
		copy[row][col] = &bishops[0];
	}

	if (to_copy->getDesignation() == 'D' || to_copy->getDesignation() == 'd') {
		queens[0].defPosition(std::vector<int> {row, col});
		copy[row][col] = &queens[0];
	}

	//if (to_copy->getDesignation() == 'K' || to_copy->getDesignation() == 'k') {
	//	king.defPosition(std::vector<int> {row, col});
	//	copy[row][col] = &king;
	//}

	return copy;
}*/

std::vector<std::vector<Character*>> Player::getQueen(std::vector<std::vector<Character*>> board, std::vector<int> pos) {

// Create a NEW board with a queen instead of the pawn
	std::vector<std::vector<Character*>> new_board(8, std::vector<Character*>(8));
	std::vector<Character> temp_queens = std::vector<Character>();
	std::vector<Character> temp_rooks = std::vector<Character>();
	std::vector<Character> temp_knights = std::vector<Character>();
	std::vector<Character> temp_bishops = std::vector<Character>();
	std::vector<Character> temp_pawns = std::vector<Character>();
	Character temp_king;

	std::vector<Character> enemy_queens = std::vector<Character>();
	std::vector<Character> enemy_rooks = std::vector<Character>();
	std::vector<Character> enemy_knights = std::vector<Character>();
	std::vector<Character> enemy_bishops = std::vector<Character>();
	std::vector<Character> enemy_pawns = std::vector<Character>();
	Character enemy_king;

	// new:
	// .create char field
	// .create countmoves field
	
	// Delete character vectors
	//delCharVecs();	
	
	// .create new board by assigning new 

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == nullptr || (i == pos[0] && j == pos[1]))
				continue;
			if (board[i][j]->getPlayer() == id) {
				if (board[i][j]->getDesignation() == 'T' || board[i][j]->getDesignation() == 't') {
					temp_rooks.push_back(*board[i][j]);
					new_board[i][j] = &temp_rooks[temp_rooks.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'S' || board[i][j]->getDesignation() == 's') {
					temp_knights.push_back(*board[i][j]);
					new_board[i][j] = &temp_knights[temp_knights.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'L' || board[i][j]->getDesignation() == 'l') {
					temp_bishops.push_back(*board[i][j]);
					new_board[i][j] = &temp_bishops[temp_bishops.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'D' || board[i][j]->getDesignation() == 'd') {
					temp_queens.push_back(*board[i][j]);
					new_board[i][j] = &temp_queens[temp_queens.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'B' || board[i][j]->getDesignation() == 'b') {
					temp_pawns.push_back(*board[i][j]);
					new_board[i][j] = &temp_pawns[temp_pawns.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'K' || board[i][j]->getDesignation() == 'k') {
					temp_king = *board[i][j];
					new_board[i][j] = &temp_king;
				}
			}
			else {	// enemy
				if (board[i][j]->getDesignation() == 'T' || board[i][j]->getDesignation() == 't') {
					enemy_rooks.push_back(*board[i][j]);
					new_board[i][j] = &enemy_rooks[enemy_rooks.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'S' || board[i][j]->getDesignation() == 's') {
					enemy_knights.push_back(*board[i][j]);
					new_board[i][j] = &enemy_knights[enemy_knights.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'L' || board[i][j]->getDesignation() == 'l') {
					enemy_bishops.push_back(*board[i][j]);
					new_board[i][j] = &enemy_bishops[enemy_bishops.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'D' || board[i][j]->getDesignation() == 'd') {
					enemy_queens.push_back(*board[i][j]);
					new_board[i][j] = &enemy_queens[enemy_queens.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'B' || board[i][j]->getDesignation() == 'b') {
					enemy_pawns.push_back(*board[i][j]);
					new_board[i][j] = &enemy_pawns[enemy_pawns.size() - 1];
				}
				if (board[i][j]->getDesignation() == 'K' || board[i][j]->getDesignation() == 'k') {
					enemy_king = *board[i][j];
					new_board[i][j] = &enemy_king;
				}
			}
		}
	}
	
	if (board[pos[0]][pos[1]]->getPlayer() == 1) {
		this->queens.push_back(Queen());
		this->queens[queens.size() - 1].assign('D', 1);
	}
	else {
		this->queens.push_back(Queen());
		this->queens[queens.size() - 1].assign('d', 2);
	}
	
	this->queens[queens.size() - 1].defPosition(pos);
	new_board[pos[0]][pos[1]] = &queens[queens.size() - 1];

	return new_board;	
}

void Player::kill(std::vector<int> pos) {
	// loop through characters and delete character with designatuion "c"
	// ...
}

Player::~Player() {}
