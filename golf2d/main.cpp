#include "game.h"

int main(int argc, char* argv[]) {
	Game game;
	game.start("Golf2d");

	while (game.running) {
		game.HandleEvents();
		game.update();
		game.render();

	}
	
	game.cleanup();
	return 0;
}
