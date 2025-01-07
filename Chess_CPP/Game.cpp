#include "Game.h"

Game::Game() {}

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

    // Initialize renderer
    Renderer renderer(8, 100);

    initPlayer("Player1", "Player2");
    this->board = white.putChars(this->board);
    this->board = black.putChars(this->board);

    // Initialize player's possible moves
    this->playerMoves = std::vector<PlayerMoves> { PlayerMoves(), PlayerMoves() };

    // Initialize test engine
    Test test = Test();

    // Main loop
    int winner = 0;;
    int act_player = 1;       // white begins
    Action action = Action();
    bool active = true;
    while (active) {
        // TEST MOVES
        //this->board = test.move(board);

        // Print board to console
        action.printBoard(board);
        renderer.render(board);
        
        // Get all possible moves of player
        playerMoves[act_player - 1].checkPlayerMoves(board, act_player);
        
        // CHECK IF GAME IS LOST
        if (playerMoves[act_player - 1].checkMate()) {
            if (act_player == 1)
                winner = 2;
            else
                winner = 1;
            active = false;
        }

        // Get move from renderer
        renderer.getMove(playerMoves[act_player - 1]);

        // Get the move from console input and move figure on board
        //action.moveFromConsole(act_player, playerMoves[act_player - 1]);
        //board = board[action.from[0]][action.from[1]]->move(board, std::vector<int> {action.to[0], action.to[1]});
        board = board[renderer.move_from[0]][renderer.move_from[1]]->move(board, std::vector<int> {renderer.move_to[0], renderer.move_to[1]});
        //std::vector<std::vector<int>> playerMove = action.getMoves(act_player); 

        // Switch player
        if (act_player == 1)
            act_player = 2;
        else
            act_player = 1;
    }

    return 0;
}

Game::~Game() {}
