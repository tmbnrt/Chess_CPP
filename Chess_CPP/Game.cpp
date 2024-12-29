#include "Game.h"

#include <iostream>
#include <string>

Game::Game() {}

static void test_print(std::vector<std::vector<Character*>> board) {
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

    Test test = Test();

    // Main loop
    int act_turn = 1;       // white begins
    Action action = Action();
    bool active = true;
    while (active) {
        if (act_turn == 1)

        // TEST MOVES
        this->board = test.move(board);

        // print board to console
        action.printBoard(board);

        test.possibleMoves(board);

        

        // Switch player
        if (act_turn == 1)
            act_turn = 2;
        else
            act_turn = 1;
        //active = false;
    }

    return 0;
}

Game::~Game() {}
