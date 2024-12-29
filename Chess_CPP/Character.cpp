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

void Character::checkMoves(std::vector<std::vector<Character*>> board) {}

int Character::getPlayer() const {
    return player;
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

void Character::getPlayersPositions(std::vector<std::vector<Character*>> board) {
    bool print = true;
    std::vector<std::vector<int>> field(8, std::vector<int>(8));
    this->playersPositions = field;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] != nullptr)
                this->playersPositions[i][j] = board[i][j]->getPlayer();
                //this->playersPositions[i][j] = board[i][j]->getPlayer(board[i][j]);
            else
                this->playersPositions[i][j] = 0;

            if (print)
                std::cout << " " << playersPositions[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<Character*>> Character::move(std::vector<std::vector<Character*>> board, std::vector<int> target) {
    // Copy figure on board and delete reference figure
    board[target[0]][target[1]] = board[position[0]][position[1]];
    board[position[0]][position[1]] = nullptr;
    this->position = target;
    this->countMoves++;

    return board;
}

int Character::getPoints() {
    return points;
}

Character::~Character() {}
