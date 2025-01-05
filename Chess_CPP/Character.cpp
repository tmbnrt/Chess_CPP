#include "Character.h"

#include<iostream>

Character::Character() {
    this->points = int();
    this->countMoves = int();
    this->designation = char();
    this->player = int();

    std::vector<std::vector<int>> chessZone(8, std::vector<int>(8));
    this->chessZone = chessZone;
}

char Character::getDesignation() const {
	return designation;
}

std::vector<std::vector<int>> Character::getRescueMovesFrom() const {
    return std::vector<std::vector<int>>();
}

std::vector<std::vector<int>> Character::getRescueMovesTo() const {
    return std::vector<std::vector<int>>();
}

void Character::checkMoves(std::vector<std::vector<Character*>> board, bool friendlyFire, bool checkRescue) {}

int Character::getPlayer() const {
    return player;
}

bool Character::isChess() const {
    if (points < 10)
        return false;
}

bool Character::isRescued() const {
    if (points < 10)
        return false;
}

int Character::numberOfMoves() {
    return countMoves;
}

void Character::assign(char c, int p) {
	this->designation = c;
	this->player = p;
}

void Character::defPosition(std::vector<int> pos) {
    this->position = pos;
}

std::vector<std::vector<int>> Character::getMoves() {
    return moves;
}

std::vector<std::vector<int>> Character::getKills() {
    return kills;
}

void Character::delMoves() {
    this->moves.clear();
}

void Character::delKills() {
    this->kills.clear();
}

void Character::getPlayersPositions(std::vector<std::vector<Character*>> board) {
    bool print = false;
    std::vector<std::vector<int>> field(8, std::vector<int>(8));
    this->playersPositions = field;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != nullptr)
                this->playersPositions[i][j] = board[i][j]->getPlayer();
            else
                this->playersPositions[i][j] = 0;

            if (print)
                std::cout << " " << playersPositions[i][j] << " ";
        }
        if (print)
            std::cout << std::endl;
    }
    if (print)
        std::cout << std::endl;
}

void Character::store_lastKill(Character* character) {
    this->lastMove_Killed = character;
}

void Character::store_lastMove(std::vector<int> from, std::vector<int> to) {
    this->lastMove_From = from;
    this->lastMove_To = to;
}

std::vector<std::vector<Character*>> Character::move(std::vector<std::vector<Character*>> board, std::vector<int> target) {
    // Save move for reverse case
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (!board[i][j])
                continue;
            if (board[i][j]->getPlayer() == player) {
                if (board[target[0]][target[1]])
                    board[i][j]->store_lastKill(board[target[0]][target[1]]);
                else
                    board[i][j]->store_lastKill(nullptr);
                board[i][j]->store_lastMove(position, target);
             }            
        }
    }    
    
    // Copy figure on board and delete reference figure
    board[target[0]][target[1]] = board[position[0]][position[1]];
    board[position[0]][position[1]] = nullptr;
    this->position = target;
    this->countMoves++;

    return board;
}

std::vector<std::vector<Character*>> Character::reverse(std::vector<std::vector<Character*>> board) {
    // Copy figure on board and delete reference figure
    board[lastMove_From[0]][lastMove_From[1]] = board[lastMove_To[0]][lastMove_To[1]];
    if (lastMove_Killed)
        board[lastMove_To[0]][lastMove_To[1]] = lastMove_Killed;
    else
        board[lastMove_To[0]][lastMove_To[1]] = nullptr;
    board[lastMove_From[0]][lastMove_From[1]]->defPosition(lastMove_From);
    this->countMoves--;

    return board;
}

int Character::getPoints() {
    return points;
}

Character::~Character() {}
