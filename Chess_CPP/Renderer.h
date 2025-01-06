#ifndef RENDERER_H
#define RENDERER_H

#include "Character.h"
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
	
	void render(const std::vector<std::vector<Character*>> board);
	// open and close window
	void										handleEvents();
	bool										isOpen() const;

private:
	sf::RenderWindow							window;
	int											boardSize;
	int											fieldSizePx;

	void										loadTextures();
	std::map<std::string, sf::Texture>			textures;
	std::map<std::string, sf::Sprite>			sprites;

	void										drawBoard();
	void										drawImages(const std::vector<std::vector<char>> board);
};

#endif RENDERER_H