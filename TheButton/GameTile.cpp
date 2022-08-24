#include "GameTile.h"


GameTile::GameTile(std::string texturePath, float x, float y, int lvl, sf::Vector2f mousePos)
{	
	
	this->initVar();
	this->initTile(texturePath, x, y, mousePos);
}

GameTile::~GameTile()
{

}

bool GameTile::setUpSprite(std::string)
{
	return false;
}

void GameTile::initVar()
{
	this->tileLvl = 1;
}

void GameTile::initTile(std::string texturePath, float x, float y, sf::Vector2f mousePos)
{
	pos = sf::Vector2f(x, y);
	this->texture.loadFromFile(texturePath);
	this->texture.setSmooth(true);
	
	this->sprite.setTexture(texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
	
	//this->sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	this->sprite.setPosition(pos);

	
	if (this->sprite.getGlobalBounds().contains(mousePos))
	{
		this->sprite.move(sf::Vector2f(4.f, 4.f));
		
	}

}

void GameTile::tileMouseHover()
{

}
