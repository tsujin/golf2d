#include "game.h"
#include <stdexcept>
#include <iostream>

void Game::start(const char* title, int width, int height) {
	IMG_Init(IMG_INIT_PNG);

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		window = SDL_CreateWindow(
			title,
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_OPENGL);

		if (!window) {
			throw std::runtime_error("Unable to create window.");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (!renderer) {
			throw std::runtime_error("Unable to create renderer.");
		}

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_Surface* tempSurface = IMG_Load("assets/ball.png");
		ballTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
		SDL_FreeSurface(tempSurface);
	}


}

void Game::cleanup() {
	SDL_DestroyTexture(ballTexture);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	IMG_Quit();
	SDL_Quit();
}


void Game::HandleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {

	case SDL_QUIT:
		running = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	
}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, ballTexture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

