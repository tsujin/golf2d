#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "ball.h"

class Game {
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Texture* ballTexture;

public:
	void start(const char* title, int width = 800, int height = 600);

	void cleanup();

	void HandleEvents();
	void update(double deltaTime);
	void render();

	bool running;
	Ball& ball;
};
