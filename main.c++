// credits to: Lazyfoo.net , "Lets Make Games" SDL youtube series
// Vittorio Romeo: " CPP CON 2015 Implementation of ECS" and "C++11-[5] Game ECS Basics" 



#include "Game.c++"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 736;

// main
int main(int argv, char** args)
{
	
	Game *game;
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game(" DYLANS DEMO! ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	 SCREEN_WIDTH, SCREEN_HEIGHT, false	);

	while(game->running())
	{

		frameStart = SDL_GetTicks();


		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();


	return 0;
}