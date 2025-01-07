#ifndef RENDERER_H
#define RENDERER_H

#include "Character.h"
#include "PlayerMoves.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Renderer
{
public:
	Renderer(int boardSize, int fieldSizePx);
	~Renderer();
	
	void										render(const std::vector<std::vector<Character*>> board);
	void										getMove(PlayerMoves& playerMoves);
	void										handleEvents();
	bool										isOpen() const;
	std::vector<int>							move_from;
	std::vector<int>							move_to;

private:
	sf::RenderWindow							window;
	int											boardSize;
	int											fieldSizePx;
	std::vector<std::vector<char>>				act_board;

	void										loadTextures();
	std::map<std::string, sf::Texture>			textures;
	std::map<std::string, sf::Sprite>			sprites;

	void										drawBoard();
	void										highlightFields(std::vector<std::vector<int>> possible);
	void										drawImages(const std::vector<std::vector<char>> board);
};

#endif RENDERER_H