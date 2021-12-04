#include "Ball.h"

Ball::Ball(Vec2DF& in_position, Vec2DF& in_speed)
	:
	position(in_position.getX(), in_position.getY()),
	speed(in_speed.getX(), in_speed.getY())
{
}

void Ball::move(float dt)
{
	position += speed.normalize() * speed_factor * dt;
}

void Ball::draw(Graphics& gfx) {
	gfx.drawCircle(int(position.getX()), int(position.getY()), radius, Colors::Green);
}

float Ball::getXCenter()
{
	return position.getX();
}

float Ball::getYCenter()
{
	return position.getY();
}

float Ball::getRadius() const
{
	return radius;
}

void Ball::setYCenter(float y_center)
{
	position.setY(y_center);
}

void Ball::setXCenter(float x_center)
{
	position.setX(x_center);
}

void Ball::invertYSpeed()
{
	speed.setY(speed.getY() * -1);
}

void Ball::invertXSpeed()
{
	speed.setX(speed.getX() * -1);
}

void Ball::bounceV(float slope, float paddle_x)
{
	if (paddle_interception) {
		speed.setX((position.getX()) * (slope));
		speed.setY(speed.getY() * -1.0f);
		paddle_interception = false;
	}
}

void Ball::enablePaddleInterception()
{
	paddle_interception = true;
}

void Ball::disablePaddleInterception()
{
	paddle_interception = false;
}
