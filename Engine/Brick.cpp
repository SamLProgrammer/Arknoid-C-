# include "Brick.h"

Brick::Brick(Vec2DF& in_position, float in_width, float in_height, Color in_c)
	:
	position(in_position.getX(), in_position.getY()),
	width(in_width),
	height(in_height),
	c(in_c)
{
}

bool Brick::operator==(Vec2DF& rh_vec)
{
	return position.getX() == rh_vec.getX() && position.getY() == rh_vec.getY();
}

void Brick::draw(Graphics& gfx)
{
	if (!removed) {
		gfx.drawRect(position.getX() + 1, position.getY() + 1, width - 1, height - 1, c);
	}
}

float Brick::getY()
{
	return position.getY();
}

float Brick::getX()
{
	return position.getX();
}

void Brick::setY(float in_y)
{
	position.setY(in_y);
}

void Brick::remove()
{
	removed = true;
}

void Brick::setX(float in_x)
{
	position.setX(in_x);
}
