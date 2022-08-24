#include "GameMap.h"
#include <iostream>

GameMap::GameMap()
{
	this->initState();
	this->initEnemyPos();
}

GameMap::~GameMap()
{
	//delete this->tiles;
}

void GameMap::initState()
{
	this->gridLen = 10;
	this->exitPos = sf::Vector2i(1, 0);

}

void GameMap::updateTiles(sf::Vector2f mousePos)
{
	tiles.clear();
	std::vector<GameTile*> row;
	std::string textureFile = "Texture/WhiteSquareBlackEdge.png";

	int originx = 350;
	int originy = 150;

	for (int i = originy; i < gridLen * 50 + originy; i += 50) {
		//clear row vector
		row.clear();
		for (int j = originx; j < gridLen * 50 + originx; j += 50) {
			//add texture tiles to row vector
			row.push_back(new GameTile(textureFile, j, i, 1, mousePos));
		}
		tiles.push_back(row);
	}
}

void GameMap::initPlayerPos()
{
	this->playerPos.push_back(sf::Vector2i(gridLen - 1, gridLen - 1));
}

void GameMap::initEnemyPos()
{
	this->enemyPos.clear();
	this->enemyPos.push_back(sf::Vector2i(0, 2));
	this->enemyPos.push_back(sf::Vector2i(6, 0));
	this->enemyPos.push_back(sf::Vector2i(2, 7));

}

