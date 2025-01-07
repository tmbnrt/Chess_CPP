// ===========================================================================
// Class: Game
// Description:
// This class contains the logic for the chess game including the main loop
// ===========================================================================
#include "Player.h"
#include "Renderer.h"
#include "Character.h"
#include "Action.h"
#include "Test.h"
#include "PlayerMoves.h"
#include<vector>
#include <iostream>
#include <string>

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
	//void										initBoard(std::vector<std::vector<Character>>& board);
	void										initPlayer(std::string name_1, std::string name_2);
	std::vector<PlayerMoves>					playerMoves;

	void										render(std::vector<std::vector<Character*>> board);

};

