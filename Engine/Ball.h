#pragma once
#include "Vec2DF.h"
#include "Graphics.h"

class Ball {
public:
	Ball(Vec2DF& in_position, Vec2DF& in_speed);
	void move(const float dt);
	void draw(Graphics& gfx);
private:
	Vec2DF position;
	Vec2DF speed;
};

