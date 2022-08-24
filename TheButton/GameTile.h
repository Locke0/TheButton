#pragma once
#include <SFML/Graphics.hpp>

class GameTile
{
public:
	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;

	//0:void, 1:land, 2:wall, 3:portal
	int tileLvl;

	GameTile(std::string, float, float, int, sf::Vector2f);
	~GameTile();

	bool setUpSprite(std::string);

	//Func
	void initVar();
	void initTile(std::string, float, float, sf::Vector2f);

	//Tile animations
	void tileMouseHover();

};

