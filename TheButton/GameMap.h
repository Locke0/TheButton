#pragma once

#include <SFML/Graphics.hpp>
#include "GameTile.h"
#include <vector>


class GameMap
{
private:
	sf::Vector2i exitPos;
	std::vector<sf::Vector2i> playerPos;
	std::vector<sf::Vector2i> enemyPos;


public:
	std::vector<std::vector<GameTile*>> tiles;
	int gridLen;
	
	GameMap();
	~GameMap();

	void initState();
	void updateTiles(sf::Vector2f mousePos);
	void initPlayerPos();
	void initEnemyPos();
};

