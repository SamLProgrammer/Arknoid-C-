#include "Ball.h"

Ball::Ball(Vec2DF& in_position, Vec2DF& in_speed)
{
	position = in_position;
	speed = in_speed;
}

void Ball::move(float dt, int left_limit, int bottom_limit, int right_limit, int upper_limit)
{
	position += speed * dt;
	if (position.getX() + radius >= right_limit) {
		position.setX(right_limit - radius);
		speed.setX(speed.getX() * -1.0f);
	}
	if (position.getY() + radius >= bottom_limit) {
		position.setY(bottom_limit - radius);
		speed.setY(speed.getY() * -1.0f);
	}
	if (position.getX() - radius <= left_limit) {
		position.setX(left_limit + radius);
		speed.setX(speed.getX() * -1.0f);
	}
	if (position.getY() - radius <= upper_limit) {
		position.setY(upper_limit + radius);
		speed.setY(speed.getY() * -1.0f);
	}
}

void Ball::draw(Graphics& gfx) {
	gfx.drawCircle(int(position.getX()), int(position.getY()), 10, Colors::Green);
}
