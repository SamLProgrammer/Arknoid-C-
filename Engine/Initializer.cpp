#include "Initializer.h"

Initializer::Initializer()
{
	float brick_width = Graphics::ScreenWidth / bricks_h_amount;
	float brick_height = 15;
	int brick_index = 0;
	for (int j = 0; j < bricks_v_amount; j++) {
		for (int i = 0; i < bricks_h_amount; i++) {
			bricks[brick_index] = Brick(Vec2DF((i) * brick_width, brick_height * j),
			brick_width, brick_height, Colors::Red);
			brick_index++;
		}
	}
}

void Initializer::drawBricks(Graphics& gfx)
{
	for (int i = 0; i < bricks_amount; i++) {
		bricks[i].draw(gfx);
	}
}
