#include "ball.h"

Vec2f Vec2f::operator +(Vec2f& other) {
	float new_x = this->x + other.x;
	float new_y = this->y + other.y;

	return Vec2f{ x = new_x, y = new_y };
}

Ball::Ball(Vec2f position) {
	this->position = position;
}
