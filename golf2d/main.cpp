#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

int main(int argc, char* args[]) {
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	bool quit = false;
	SDL_Event input;
	SDL_Rect sourceRectangle, destinationRectangle;

	window = SDL_CreateWindow(
		"Golf2d",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800,
		600,
		SDL_WINDOW_OPENGL);

	if (!window) {
		std::cout << "Could not create window.";
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	if (!renderer) {
		std::cout << "Could not create renderer.";
		return 1;
	}

	SDL_Texture* ballTexture;
	SDL_Surface* tempSurface = IMG_Load("assets/ball.png");

	if (!tempSurface) {
		std::cout << IMG_GetError();
		return 1;
	}

	ballTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);

	if (!ballTexture) {
		std::cout << SDL_GetError();
		return 1;
	}

	destinationRectangle.x = 0;
	destinationRectangle.y = 0;
	destinationRectangle.h = 32;
	destinationRectangle.w = 32;


	while (!quit) {
		while (SDL_PollEvent(&input) > 0) {
			if (input.type == SDL_QUIT) quit = true;
		}

		
		SDL_RenderCopy(renderer, ballTexture, NULL, &destinationRectangle);
		SDL_RenderPresent(renderer);
		
	}
	
	SDL_DestroyTexture(ballTexture);
	SDL_FreeSurface(tempSurface);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	IMG_Quit();
	SDL_Quit();
	return 0;
}
