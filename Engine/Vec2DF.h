#pragma once
#include <cmath>
class Vec2DF {
public:
	Vec2DF() = default;
	Vec2DF(float in_x, float in_y);
	bool operator==(Vec2DF& rh_vec) const;
	Vec2DF operator+(Vec2DF& rh_vec) const;
	Vec2DF& operator+=(Vec2DF& rh_vec);
	Vec2DF operator*(float scalar) const;
	Vec2DF& operator*=(float scalar);
	Vec2DF operator-(Vec2DF& rh_vec) const;
	Vec2DF& operator-=(Vec2DF& rh_vec);
	float length() const;
	float sqrdLength() const;
	Vec2DF& normalize();
	Vec2DF getNormalized() const;
	float getX();
	float getY();
	void setX(float in_x);
	void setY(float in_y);
private:
	float x;
	float y;
};