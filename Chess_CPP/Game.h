// ===========================================================================
// Class: Game
// Description:
// This class contains the logic for the chess game including the main loop
// ===========================================================================
#include "Player.h"
#include "Character.h"
#include "Action.h"
#include<vector>

class Game
{
public:
	Game();
	~Game();

	std::vector<std::vector<Character*>>		board;
	Player										white;
	Player										black;
	int											start();

private:	
	void										initBoard(std::vector<std::vector<Character>>& board);
	void										initPlayer(std::string name_1, std::string name_2);



};

