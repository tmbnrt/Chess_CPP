#ifndef PREDICTION_H
#define PREDICTION_H

#include "PlayerMoves.h"
#include "Character.h"
#include <string>
#include <vector>
#include <iostream>

class Prediction
{
public:
	Prediction();
	~Prediction();
	void										inputProcess(std::vector<std::vector<Character*>> board, PlayerMoves playerMoves);
	void										predict();
	std::vector<std::vector<int>>				getMove();

private:
	std::vector<std::vector<char>>				charBoard;
	std::vector<std::vector<int>>				moves_from;
	std::vector<std::vector<int>>				moves_to;
	std::vector<int>							predicted_from;
	std::vector<int>							predicted_to;
	int											moveCounter;
	void										updateCharBoard(std::vector<std::vector<Character*>> board);

};

#endif PREDICTION_H