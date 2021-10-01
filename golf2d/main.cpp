#include "game.h"
#include <iostream>

int main(int argc, char* argv[]) {
	Game game;
	game.start("Golf2d");
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
	double deltaTime = 0;

	while (game.running) {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST) * 1000 / (double)SDL_GetPerformanceFrequency());
		game.HandleEvents();
		game.update(deltaTime);
		game.render();

		std::cout << deltaTime << "\n";
	}
	
	game.cleanup();
	return 0;
}
