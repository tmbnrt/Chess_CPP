// ===========================================================================
// BaseClass: Character
// Description:
// This is the base class for the game characters (King, Queen, Bishop, etc.)
// ===========================================================================
#ifndef CHARACTER_H
#define CHARACTER_H

#include "DangerZone.h"
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
	std::vector<std::vector<int>>				chessZone;
	std::vector<std::vector<int>>				kills;
	std::vector<std::vector<int>>				moves;
	//void										createDangerZone(std::vector<std::vector<Character*>> board);

public:
	Character();
	virtual ~Character();
	virtual void								assign(char c, int p);
	virtual char								getDesignation() const;
	virtual void								checkMoves(std::vector<std::vector<Character*>> board, bool friendlyFire = false);
	int											getPoints();
	int											numberOfMoves();
	int											getPlayer() const;
	void                                        defPosition(std::vector<int> pos);	
	std::vector<std::vector<Character*>>		move(std::vector<std::vector<Character*>> board, std::vector<int> target);
	std::vector<std::vector<int>>				getMoves();
	std::vector<std::vector<int>>				getKills();
	void										delMoves();
	void										delKills();
};

#endif // CHARACTER_H
