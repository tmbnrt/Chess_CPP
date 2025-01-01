// ===========================================================================
// Class: Action
// Description:
// This class is the communication and instruction interface for both players.
// ===========================================================================
#ifndef ACTION_H
#define ACTION_H

#include "Character.h"
#include <vector>
#include <iostream>
#include <sstream>

class Action
{
public:
	Action();
	~Action();
	std::vector<std::vector<int>>				getMoves(int player);
	void										updateMoves(std::vector<std::vector<int>> moves, std::vector<std::vector<int>> kills, int player);
	void										printBoard(std::vector<std::vector<Character*>> board);
	void										moveFromConsole(int player);

private:
	std::vector<std::vector<int>>				charBoard;
	std::vector<std::vector<int>>				movesPlayer_1;
	std::vector<std::vector<int>>				movesPlayer_2;
	bool										moveAllowed(std::vector<int> from, std::vector<int> to, int player);

};

#endif ACTION_H