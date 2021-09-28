#pragma once
#include <SDL.h>

struct Vec2f {
	float x, y;
};

class Ball {
	SDL_Texture* sprite;

public:
	Vec2f position, velocity;
	float operator +(Vec2f& other);
	void update();
};