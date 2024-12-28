#include "Game.h"
#include "Character.h"
#include "Player.h"
#include "Action.h"

#include <iostream>
#include <vector>
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
        this->board = board[6][2]->move(board, std::vector<int> {3, 2});
        this->board = board[1][1]->move(board, std::vector<int> {2, 1});

        // print board to console
        test_print(board);

        //Action allowed2 = board[1][1]->checkMoves(board);
        Action allowed1 = board[2][1]->checkMoves(board);

        // test - enemym friendly - position
        //this->board[1][1]->getPlayersPositions(board);

        active = false;
    }

    return 0;
}

Game::~Game() {}
