#include "Game.h"


int main()
{
	//Init srand
	std::srand(static_cast<unsigned>(time(NULL)));


	//Init Game engine
	Game game;

	//Game loop
	while (game.isRunning())
	{

		//Update
		game.update();

		//Render
		game.render();


	}

	//End of game
}