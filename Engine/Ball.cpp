#include "Ball.h"

Ball::Ball(Vec2DF& in_position, Vec2DF& in_speed)
{
	position = in_position;
	speed = in_speed;
}

void Ball::move(const float dt)
{
	position += speed * dt;
}

void Ball::draw(Graphics& gfx) {
	gfx.drawCircle((int)position.getX(), (int)position.getY(), 10, Colors::Green);
}
