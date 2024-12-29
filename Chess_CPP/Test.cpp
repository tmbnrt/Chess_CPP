#include "Test.h"

Test::Test() {}


std::vector<std::vector<Character*>> Test::move(std::vector<std::vector<Character*>> board) {
	// TEST MOVES
	board = board[0][5]->move(board, std::vector<int> {4, 5});
	board = board[7][4]->move(board, std::vector<int> {4, 3});
	board = board[1][3]->move(board, std::vector<int> {3, 3});
	board = board[0][3]->move(board, std::vector<int> {2, 6});
	board = board[0][1]->move(board, std::vector<int> {1, 3});

	return board;
}

void Test::possibleMoves(std::vector<std::vector<Character*>> board) {
	// CHECK POSSIBILITIES
	board[4][3]->checkMoves(board);
	//board[5][5]->checkMoves(board);

	std::vector<std::vector<int>> king_moves = board[4][3]->getMoves();
	std::vector<std::vector<int>> king_kills = board[4][3]->getKills();
	//std::vector<std::vector<int>> queen_moves = board[5][5]->getMoves();
	//std::vector<std::vector<int>> queen_kills = board[5][5]->getKills();
}

Test::~Test(){}