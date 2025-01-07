#include "Renderer.h"
//#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <windows.h>

Renderer::Renderer(int boardSize, int fieldSizePx) : boardSize(boardSize), fieldSizePx(fieldSizePx) {
	window.create(sf::VideoMode(boardSize * fieldSizePx, boardSize * fieldSizePx), "Chessboard Renderer");
	
	loadTextures();
}

std::string getExecutablePath() {
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string exePath = buffer;
	return std::filesystem::path(exePath).parent_path().string();
}

void Renderer::loadTextures() {
	std::string exeFolder = getExecutablePath();

	// Define images
	std::vector<std::vector<std::string>> imagePaths;
	imagePaths.push_back({"1_K", exeFolder + "/images/1_K.png"}),
	imagePaths.push_back({"1_D", exeFolder + "/images/1_D.png"}),
	imagePaths.push_back({"1_T", exeFolder + "/images/1_T.png"}),
	imagePaths.push_back({"1_S", exeFolder + "/images/1_S.png"}),
	imagePaths.push_back({"1_L", exeFolder + "/images/1_L.png"}),
	imagePaths.push_back({"1_B", exeFolder + "/images/1_B.png"}),
	imagePaths.push_back({"2_k", exeFolder + "/images/2_k.png"}),
	imagePaths.push_back({"2_d", exeFolder + "/images/2_d.png"}),
	imagePaths.push_back({"2_t", exeFolder + "/images/2_t.png"}),
	imagePaths.push_back({"2_s", exeFolder + "/images/2_s.png"}),
	imagePaths.push_back({"2_l", exeFolder + "/images/2_l.png"}),
	imagePaths.push_back({"2_b", exeFolder + "/images/2_b.png"});

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
	this->act_board = board;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] == '0')
				continue;

			// Check capital letter
			std::string figure;
			if (static_cast<int>((board[i][j] - 91) < 0)) {
				figure = "1_";
				figure += board[i][j];
			}			
			else {
				figure = "2_";
				figure += board[i][j];
			}
			
			sf::Sprite sprite = sprites[figure];
			sprite.setPosition(j * fieldSizePx, i * fieldSizePx);
			window.draw(sprite);
		}
	}
}

void Renderer::highlightFields(std::vector<std::vector<int>> allowed) {
	window.clear();
	drawBoard();
	drawImages(act_board);
	
	for (const auto& highlight : allowed) {
		sf::RectangleShape border(sf::Vector2f(fieldSizePx, fieldSizePx));
		border.setPosition(highlight[1] * fieldSizePx, highlight[0] * fieldSizePx);
		border.setFillColor(sf::Color::Transparent);
		border.setOutlineColor(sf::Color::Red);
		border.setOutlineThickness(5);
		window.draw(border);
	}

	window.display();
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

void Renderer::getMove(PlayerMoves& playerMoves) {
	std::vector<int> actual;
	std::vector<int> target;

	bool selActPosition = true;
	bool correct_input = false;

	while (!correct_input && window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// Check input
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			// get position
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);

			int row = mousePos.y / fieldSizePx;
			int col = mousePos.x / fieldSizePx;

			// CHECK IF ALLOWED
			if (selActPosition && playerMoves.checkAllowedActual(std::vector<int>{ row, col })) {
				actual = std::vector<int>{ row, col };
				selActPosition = false;

				// Mark targets
				highlightFields(playerMoves.getTargets(actual));
			}
			else if (!selActPosition) {
				target = std::vector<int>{ row, col };
				if ((target[0] == actual[0] && target[1] == actual[1]) || playerMoves.checkAllowedActual(std::vector<int>{ target[0], target[1] })) {
					// unmark board
					std::vector<std::vector<int>> empty;
					//window.clear();
					//drawBoard();
					//drawImages(act_board);
					highlightFields(empty);
					selActPosition = true;
					continue;
				}

				if (playerMoves.checkAllowed(actual, target)) {
					correct_input = true;
					playerMoves.addHistory(actual, target);
					this->move_from = actual;
					this->move_to = target;
				}
				else {
					drawBoard();
					drawImages(act_board);
					selActPosition = true;
					continue;
				}
			}
		}
	}
}

Renderer::~Renderer() {}
