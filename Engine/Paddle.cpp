#include "Paddle.h"

Paddle::Paddle(Vec2DF& in_position, Vec2DF& in_speed)
	:
	position(in_position.getX(), in_position.getY()),
	speed(in_speed.getX(), in_speed.getY())
{
}

void Paddle::move(float dt, bool right) {
	position += speed * dt;
	if (position.getX() < 0) {
		position.setX(0);
	}
	if (position.getX() + width >= Graphics::ScreenWidth) {
		position.setX(Graphics::ScreenWidth - width);
	}
	if (right) {
		speed.setX(hrz_speed);
	}
	else {
		speed.setX(hrz_speed*-1);
	}
}

void Paddle::draw(Graphics& gfx){
	gfx.drawRect(int(position.getX()), int(position.getY()), width, height, Colors::Blue);
}

float Paddle::getX()
{
	return position.getX();
}

float Paddle::getY()
{
	return position.getY();
}
