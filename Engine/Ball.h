#pragma once
#include "Vec2DF.h"
#include "Graphics.h"

class Ball {
public:
	Ball(Vec2DF& in_position, Vec2DF& in_speed);
	void move(float dt, int left_limit, int bottom_limit, int right_limit, int upper_limit);
	void draw(Graphics& gfx);
	float radius = 10.0f;
private:
	Vec2DF position;
	Vec2DF speed;
};

