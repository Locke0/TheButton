#include "Game.h"


void Game::initVar()
{
	this->window = nullptr;

	//Game Logic
	this->endGame = false;
	this->points = 0;
	this->health = 10;

	this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videoMode.height = 900;
	this->videoMode.width = 1200;

	this->window = new sf::RenderWindow(this->videoMode, "THE MAZE", sf::Style::Titlebar | sf::Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
	this->font.loadFromFile("Fonts/CONSOLA.ttf");
}

void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setPosition(10.f, 8.f);
	this->uiText.setCharacterSize(16);
	this->uiText.setFillColor(sf::Color::White);
	//this->uiText.setStyle(sf::Text::Bold);

}

void Game::initGameMap()
{
	
}



Game::Game()
{
	this->initVar();
	this->initWindow();
	this->initFonts();
	this->initText();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::isRunning() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return false;
}

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{

		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (ev.key.code == sf::Keyboard::F)
				this->window->close();
			//this->window->create(this->videoMode, "Maze", sf::Style::Fullscreen);
			break;

		}
	}
}

void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		//Update mouse position
		this->updateMousePositions();

		//Update text
		this->updateText();

		//Update enemies
		
		//Update map
		this->updateMap();
	}

	//End game condition
	if (this->health <= 0)
		this->endGame = true;
}

void Game::render()
{
	/*
	@return void
	- Clear old frame
	- Render objects
	- Display frame in window
*/

	this->window->clear(sf::Color::Black);

	//Draw game objects
	this->renderMap();
	this->renderButtons();
	

	this->renderText(*this->window);

	

	this->window->display();
}

void Game::updateMousePositions()
{
	/*
	@return void

	Updates the mouse positions

	- Mouse position relative to window (Vector2i)

*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);

}

void Game::updateMap()
{
	gameMap.updateTiles(this->mousePosView);
}

void Game::renderMap()
{
	this->updateMap();

	for (int i = 0; i < gameMap.gridLen; i++)
	{
		for (int j = 0; j < gameMap.gridLen; j++)
		{

			this->window->draw(gameMap.tiles[i][j]->sprite);
		}
	}
}

void Game::updateText()
{
	
	sf::String myString = L"\x2665 " + std::to_wstring(this->health) + L"\n" 
		+ L"\x0024 " + std::to_wstring(this->points);

	myString = L"##########\n";
	myString += L"#........#\n";
	myString += L"#........#\n";
	myString += L"#........#\n";
	myString += L"##########\n";

	this->uiText.setString(myString);
}

void Game::renderText(sf::RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderButtons()
{	
	sf::Texture t;
	t.loadFromFile("Texture/GreenButton.png");
	t.setSmooth(true);
	this->greenButton.setPosition(400.f, 700.f);
	this->greenButton.setRadius(50);
	this->greenButton.setFillColor(sf::Color::Green);
	this->greenButton.setTexture(&t);
	this->greenButton.setOutlineThickness(5);
	this->greenButton.setOutlineColor(sf::Color::White);
	this->window->draw(this->greenButton);


}
