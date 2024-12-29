#include "DangerZone.h"

DangerZone::DangerZone() {}

std::vector<std::vector<int>> DangerZone::getDangerZone() {
	return dangerZone;
}

void DangerZone::updateDangerZone(std::vector<std::vector<int>> enemyMoves, std::vector<std::vector<int>> zone) {
	std::vector<std::vector<int>> newZone = zone;
	for (int i = 0; i < enemyMoves.size(); i++)
		newZone[enemyMoves[i][0]][enemyMoves[i][1]] = 1;

	this->dangerZone = newZone;
}

bool DangerZone::noChess(std::vector<int> kingPos) {
	if (dangerZone[kingPos[0]][kingPos[1]] == 1)
		return false;

	return true;
}

void DangerZone::updateDangerZonePawns(std::vector<std::vector<int>> zone, int i, int j, int player) {
	std::vector<std::vector<int>> newZone = zone;
	if (player == 2)
	{
		if (i < 7 && j >= 1)
			newZone[i + 1][j - 1] = 1;
		if (i < 7 && j < 7)
			newZone[i + 1][j + 1] = 1;
	}
	else {
		if (i >= 1 && j >= 1)
			newZone[i - 1][j - 1] = 1;
		if (i >= 1 && j < 7)
			newZone[i - 1][j + 1] = 1;
	}

	this->dangerZone = newZone;
}

void DangerZone::createDangerZone(std::vector<std::vector<Character*>> board, int player) {
	std::vector<std::vector<int>> zone(8, std::vector<int>(8));
	this->dangerZone = zone;

	for (int i = 0; i < zone.size(); i++)
		for (int j = 0; j < zone[0].size(); j++)
			this->dangerZone[i][j] = 0;

	//std::vector<std::vector<int>> dangerCoords = std::vector<std::vector<int>>();

	int enemy = 1;
	if (player == 1)
		enemy = 2;

	for (int i = 0; i < dangerZone.size(); i++) {
		for (int j = 0; j < dangerZone[0].size(); j++) {
			if (board[i][j] == nullptr)
				continue;
			if (board[i][j]->getPlayer() == player)
				continue;

			if (board[i][j]->getPoints() == 1) {
				updateDangerZonePawns(dangerZone, i, j, player);
			}
			else {
				std::vector<std::vector<int>> enemyMoves = board[i][j]->getMoves();
				updateDangerZone(enemyMoves, dangerZone);
			}
		}
	}
}

DangerZone::~DangerZone(){}
