#pragma once
#include <SDL.h>

struct Vec2f { 
	float x, y; 
	float operator +(Vec2f& other);
};

class Ball {
	SDL_Texture* sprite;

public:
	Vec2f position, velocity;
	Ball(Vec2f position);
	
	void update();
};
