#ifndef PLAYERMOVES_H
#define PLAYERMOVES_H

#include "Character.h"
#include <vector>

class PlayerMoves
{
public:
	PlayerMoves();
	~PlayerMoves();
	int											player;
	bool										checkAllowed(std::vector<int> actual, std::vector<int> target);
	void										clear();
	void										checkPlayerMoves(std::vector<std::vector<Character*>> board, int player);
	void										addHistory(std::vector<int> actual, std::vector<int> target);
	bool										isChess() const;

private:
	std::vector<std::vector<int>>				from;
	std::vector<std::vector<int>>				to;
	std::vector<std::vector<int>>				history_from;
	std::vector<std::vector<int>>				history_to;
	bool										chess;
};

#endif PLAYERMOVES_H