// ===========================================================================
// BaseClass: Character
// Description:
// This is the base class for the game characters (King, Queen, Bishop, etc.)
// ===========================================================================
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Action.h"

#include<string>
#include<vector>

class Character
{
protected:
	char										designation;
	int											player;
	int											points;
	int                                         countMoves;
	std::vector<int>							position;
	std::vector<std::vector<int>>				playersPositions;
	void										getPlayersPositions(std::vector<std::vector<Character*>> board);

public:
	Character();
	virtual void								assign(char c, int p);
	virtual char								getDesignation() const;
	int											getPoints();
	int											numberOfMoves();
	int											getPlayer(Character*) const ;
	void                                        defPosition(std::vector<int> pos);
	virtual Action								checkMoves(std::vector<std::vector<Character*>> board);
	std::vector<std::vector<Character*>>		move(std::vector<std::vector<Character*>> board, std::vector<int> target);
	virtual ~Character();

private:
	
};

#endif