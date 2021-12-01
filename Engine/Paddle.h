#pragma once
#include "Vec2DF.h"
#include "Graphics.h"

class Paddle {
public:
	Paddle(Vec2DF& position, Vec2DF& speed);
	void move(float dt, bool right);
	void draw(Graphics& gfx);
	static constexpr float hrz_speed = 10.0f;
	static constexpr int height = 12;
	static constexpr int width = 80;
private:
	Vec2DF position;
	Vec2DF speed;
};