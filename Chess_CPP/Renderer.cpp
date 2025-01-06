#include "Renderer.h"
//#include <stdexcept>
#include <iostream>

Renderer::Renderer(int boardSize, int fieldSizePx) : boardSize(boardSize), fieldSizePx(fieldSizePx) {
	window.create(sf::VideoMode(boardSize * fieldSizePx, boardSize * fieldSizePx), "Chessboard Renderer");
	
	loadTextures();
}

void Renderer::loadTextures() {
	// Define images
	std::vector<std::vector<std::string>> imagePaths;
	imagePaths.push_back({"1_K", "images/1_K.png"}),
	imagePaths.push_back({"1_D", "images/1_D.png"}),
	imagePaths.push_back({"1_T", "images/1_T.png"}),
	imagePaths.push_back({"1_S", "images/1_S.png"}),
	imagePaths.push_back({"1_L", "images/1_L.png"}),
	imagePaths.push_back({"1_B", "images/1_B.png"}),
	imagePaths.push_back({"1_k", "images/1_k.png"}),
	imagePaths.push_back({"1_d", "images/1_d.png"}),
	imagePaths.push_back({"1_t", "images/1_t.png"}),
	imagePaths.push_back({"1_s", "images/1_s.png"}),
	imagePaths.push_back({"1_l", "images/1_l.png"}),
	imagePaths.push_back({"1_b", "images/1_b.png"});

	for (int i = 0; i < imagePaths.size(); i++) {
		std::string image = imagePaths[i][0];
		std::string& path = imagePaths[i][1];

		sf::Texture texture;
		if (!texture.loadFromFile(path))
			throw std::runtime_error("Error while loading the file: " + path);

		textures[image] = texture;

		// Create sprite
		sf::Sprite sprite(textures[image]);
		sprites[image] = sprite;
	}
}

void Renderer::drawBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			sf::RectangleShape square(sf::Vector2f(fieldSizePx, fieldSizePx));
			square.setPosition(j * fieldSizePx, i * fieldSizePx);

			// Chess board color
			if ((i + j) % 2 == 0)
				square.setFillColor(sf::Color::White);
			else
				square.setFillColor(sf::Color(100, 100, 100));
			window.draw(square);
		}
	}
}

void Renderer::drawImages(const std::vector<std::vector<char>> board) {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j ]== '0')
				continue;

			// Check capital letter
			std::string figure;
			if (static_cast<int>((board[i][j] - 91) < 0))
				figure = "1_" + board[i][j];
			else
				figure = "2_" + board[i][j];
			
			sf::Sprite sprite = sprites[figure];
			sprite.setPosition(j * fieldSizePx, i * fieldSizePx);
			window.draw(sprite);
		}
	}
}

void Renderer::render(const std::vector<std::vector<Character*>> board) {
	std::vector<std::vector<char>> charBoard(8, std::vector<char>(8));
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] != nullptr)
				charBoard[i][j] = board[i][j]->getDesignation();
			else
				charBoard[i][j] = '0';
		}
	}

	window.clear();
	drawBoard();
	drawImages(charBoard);
	window.display();
}

void Renderer::handleEvents() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

bool Renderer::isOpen() const {
	return window.isOpen();
}

Renderer::~Renderer() {}
