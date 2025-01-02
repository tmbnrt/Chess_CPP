#include "Game.h"

Game::Game() {}

/*
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
}*/

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

    // Initialize player's possible moves
    this->playerMoves = std::vector<PlayerMoves> { PlayerMoves(), PlayerMoves() };

    // Initialize test engine
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
        playerMoves[act_player - 1].checkMoves(board, act_player);
        

        // Get the move from console input and move figure on board
        //action.updateMoves(playerMoves[act_player - 1], act_player);
        action.moveFromConsole(act_player, playerMoves[act_player - 1]);
        //std::vector<std::vector<int>> playerMove = action.getMoves(act_player);

        // Move figure
        board = board[action.from[0]][action.from[1]]->move(board, std::vector<int> {action.to[0], action.to[1]});

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
