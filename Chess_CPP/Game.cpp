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

    std::vector<std::vector<std::vector<int>>> moves = std::vector<std::vector<std::vector<int>>>();
    std::vector<std::vector<std::vector<int>>> kills = std::vector<std::vector<std::vector<int>>>();
    std::vector<std::vector<int>> fig_mve;
    std::vector<std::vector<int>> fig_kll;

    initPlayer("Player1", "Player2");
    this->board = white.putChars(this->board);
    this->board = black.putChars(this->board);

    Test test = Test();

    // Main loop
    int act_player = 1;       // white begins
    Action action = Action();
    bool active = true;
    while (active) {
        // TEST MOVES
        //this->board = test.move(board);

        // Print board to console
        action.printBoard(board);

        // Get all possible moves of player
        // ... (input: moves, kills, player) --> for all remaining figures (loop)
        moves.clear();
        kills.clear();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                if (board[i][j]->getPlayer() == act_player) {
                    fig_mve = board[i][j]->getMoves();
                    fig_kll = board[i][j]->getMoves();
                    moves.push_back(std::vector<>);
                    kills.push_back();
                    //... ERROR.. structure should be: Pos[][], pissobilities[][]
                }
        }

        // Get the move from console input and move figure on board
        action.updateMoves(moves, kills, act_player);
        action.moveFromConsole(act_player);
        std::vector<std::vector<int>> playerMove = action.getMoves(act_player);

        // Move figure
        board = board[playerMove[0][0]][playerMove[0][1]]->move(board, std::vector<int> {playerMove[1][0], playerMove[1][1]});

        // OUTPUT POSSIBLE MOVES
        //test.possibleMoves(board);

        // Get input from console (later switched to Renderer UI)



        // Switch player
        if (act_player == 1)
            act_player = 2;
        else
            act_player = 1;
        //active = false;
    }

    return 0;
}

Game::~Game() {}
