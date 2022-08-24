#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "GameMap.h"
#include "Buttons.h"

/*
	Game Engine
*/

class Game
{
private:
	//Var
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	//std::vector<std::string> map_sketch;


	//Resources
	sf::Font font;

	//Text
	sf::Text uiText;

	//Game logic
	bool endGame;
	unsigned points;
	int health;


	bool mouseHeld;

	//Game objects
	sf::CircleShape greenButton;

	//Game map
	GameMap gameMap;
	Buttons Button;

	//Mouse positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Func
	void initVar();
	void initWindow();
	void initFonts();
	void initText();
	void initGameMap();


public:
	Game();
	virtual ~Game();

	//Accessors
	const bool isRunning() const;
	const bool getEndGame() const;

	//Functions


	void pollEvents();

	void update();
	void render();

	void updateMousePositions();

	void updateMap();
	void renderMap();

	void updateText();
	void renderText(sf::RenderTarget& target);

	void renderButtons();

};