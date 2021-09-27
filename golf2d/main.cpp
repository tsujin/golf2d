#include <SDL.h>
#include <iostream>
#undef main

int main(int argc, char* args[]) {
	SDL_Window* window;
	SDL_Init(SDL_INIT_VIDEO);

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

	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}