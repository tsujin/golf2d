#include <SDL.h>
#include <iostream>

int main(int argc, char* args[]) {
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);
	bool quit = false;
	SDL_Event input;

	window = SDL_CreateWindow(
		"Golf2d",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL);

	if (window == nullptr) {
		std::cout << "Could not create window.";
		return 1;
	}

	while (!quit) {
		while (SDL_PollEvent(&input) > 0) {
			if (input.type == SDL_QUIT) quit = true;
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}