#include "Game.h"

#include <iostream>
#include <string>

Game::Game() {}

static void test_print(std::vector<std::vector<Character*>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != nullptr)
                std::cout << " " << board[i][j]->getDesignation() << " ";
            else
                std::cout << " 0 ";
        }            
            
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Game::initPlayer(std::string name_1, std::string name_2) {
    this->white = Player();
    this->white.assign(name_1, 1);
    this->black = Player();
    this->black.assign(name_2, 2);
}

int Game::start() {
    // Create and initialize board
    std::vector<std::vector<Character*>> init_board(8, std::vector<Character*>(8));
    this->board = init_board;

    initPlayer("Player1", "Player2");
    this->board = white.putChars(this->board);
    this->board = black.putChars(this->board);

    // Main loop
    bool active = true;
    while (active) {

        // test move figure:  figure at pos[0][0] chosen in GUI --> move this figure to new target
        this->board = board[0][5]->move(board, std::vector<int> {4, 5});
        this->board = board[7][4]->move(board, std::vector<int> {4, 3});
        this->board = board[1][3]->move(board, std::vector<int> {3, 3});
        this->board = board[0][3]->move(board, std::vector<int> {2, 6});
        this->board = board[0][1]->move(board, std::vector<int> {1, 3});

        // print board to console
        test_print(board);   

        board[4][3]->checkMoves(board);
        //board[5][5]->checkMoves(board);

        std::vector<std::vector<int>> king_moves = board[4][3]->getMoves();
        std::vector<std::vector<int>> king_kills = board[4][3]->getKills();
        //std::vector<std::vector<int>> queen_moves = board[5][5]->getMoves();
        //std::vector<std::vector<int>> queen_kills = board[5][5]->getKills();

        active = false;
    }

    return 0;
}

Game::~Game() {}
