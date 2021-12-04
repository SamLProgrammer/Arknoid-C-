# include "Brick.h"

Brick::Brick(Vec2DF& in_position, Color in_c)
	:
	position(in_position.getX(), in_position.getY()),
	c(in_c)
{
}

bool Brick::operator==(Vec2DF& rh_vec)
{
	return position.getX() == rh_vec.getX() && position.getY() == rh_vec.getY();
}
