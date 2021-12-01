#include "Vec2DF.h"

Vec2DF::Vec2DF(float in_x, float in_y)
	:
	x(in_x),
	y(in_y)
{
}

bool Vec2DF::operator==(Vec2DF& rh_vec) const
{
	return x == rh_vec.x && y == rh_vec.y;
}

Vec2DF Vec2DF::operator+(Vec2DF& rh_vec) const
{
	return Vec2DF(x + rh_vec.x, y + rh_vec.y);
}

Vec2DF& Vec2DF::operator+=(Vec2DF& rh_vec)
{
	return *this = *this + rh_vec;
}

Vec2DF Vec2DF::operator*(float scalar) const
{
	return Vec2DF(x * scalar, y * scalar);
}

Vec2DF& Vec2DF::operator*=(float scalar)
{
	return *this = *this * scalar;
}

Vec2DF Vec2DF::operator-(Vec2DF& rh_vec) const
{
	return Vec2DF(x - rh_vec.x, y - rh_vec.y);
}

Vec2DF& Vec2DF::operator-=(Vec2DF& rh_vec)
{
	return *this = *this - rh_vec;
}

float Vec2DF::length() const
{
	return std::sqrt(sqrdLength());
}

float Vec2DF::sqrdLength() const
{
	return x * x + y * y;
}

Vec2DF& Vec2DF::normalize()
{
	return *this = getNormalized();
}

Vec2DF Vec2DF::getNormalized() const
{
	if (length() > 0) {
		return *this * (1.0f / length());
	}
	return *this;
}

float Vec2DF::getX()
{
	return x;
}

float Vec2DF::getY()
{
	return y;
}

void Vec2DF::setX(float in_x)
{
	x = in_x;
}

void Vec2DF::setY(float in_y)
{
	y = in_y;
}