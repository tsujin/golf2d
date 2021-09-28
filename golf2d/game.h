#pragma once
#include <SDL.h>

class Game {
	bool _running;

public:
	void start(const char* title, int width = 800, int height = 480);

	void cleanup();

	void handleEvents();
	void update();
	void render();

	bool isRunning() { return _running; }
	void Quit() { _running = false;  }

	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* ballTexture;
};