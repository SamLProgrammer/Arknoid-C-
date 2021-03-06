#pragma once
#include "Brick.h"
#include "Graphics.h"
#include "Ball.h"
class Initializer {
public:
	Initializer();
	void drawBricks(Graphics& gfx);
	void check_collisions(Ball& ball);
private:
	static constexpr int bricks_h_amount = 20;
	static constexpr int bricks_v_amount = 10;
	static constexpr int bricks_amount = bricks_h_amount * bricks_v_amount;
	Brick bricks[bricks_amount];
};