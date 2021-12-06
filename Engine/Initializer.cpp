#include "Initializer.h"

Initializer::Initializer()
{
	float brick_width = Graphics::ScreenWidth / bricks_h_amount;
	float brick_height = 15;
	int brick_index = 0;
	for (int j = 0; j < bricks_v_amount; j++) {
		for (int i = 0; i < bricks_h_amount; i++) {
			bricks[brick_index] = Brick(Vec2DF((i)*brick_width, brick_height * j),
				brick_width, brick_height, Colors::Red);
			if (j % 2 != 0) {
				bricks[brick_index].remove();
				bricks[brick_index].setX(-100);
				bricks[brick_index].setY(-100);
			}
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

void Initializer::check_collisions(Ball& ball)
{
	float brick_width = Graphics::ScreenWidth / bricks_h_amount;
	float brick_height = 15;

	float bottom_ball = ball.getYCenter() + ball.getRadius();
	float top_ball = ball.getYCenter() - ball.getRadius();
	float east_ball = ball.getXCenter() + ball.getRadius();
	float west_ball = ball.getXCenter() - ball.getRadius();

	float distance = 200.0f;

	int collided_brick = 0;

	bool collision = false;

	for (int i = 0; i < bricks_amount; i++) {

		float east_brick = bricks[i].getX() + brick_width;
		float bottom_brick = bricks[i].getY() + brick_height;

		float aux_distance = (Vec2DF(bricks[i].getX() + brick_width / 2, bricks[i].getY() + brick_height / 2) -
			Vec2DF(ball.getXCenter(), ball.getYCenter())).length();

		bool in_horizontal_range = ball.getXCenter() >= bricks[i].getX() && ball.getXCenter() <= east_brick;

		bool in_vertical_range = ball.getYCenter() >= bricks[i].getY() && ball.getYCenter() <= bottom_brick;

		//North Collision
		if (bottom_ball >= bricks[i].getY() && bottom_ball <= bottom_brick && in_horizontal_range) {
			collision = true;
			ball.invertYSpeed();
			if (aux_distance < distance) {
				distance = aux_distance;
				collided_brick = i;
			}
		}
		//South Collision
		else if (top_ball <= bottom_brick && top_ball >= bricks[i].getY() && in_horizontal_range) {
			collision = true;
			ball.invertYSpeed();
			if (aux_distance < distance) {
				distance = aux_distance;
				collided_brick = i;
			}
		} 
		//West Collision
		else if (east_ball >= bricks[i].getX() && east_ball <= east_brick && in_vertical_range) {
			collision = true;
			ball.invertXSpeed();
			if (aux_distance < distance) {
				distance = aux_distance;
				collided_brick = i;
			}
		} 
		//East Collision
		else if (west_ball <= east_brick && west_ball >= bricks[i].getX() && in_vertical_range) {
			collision = true;
			ball.invertXSpeed();
			if (aux_distance < distance) {
				distance = aux_distance;
				collided_brick = i;
			}
		}
	}
	if (collision) {
		bricks[collided_brick].remove();
		bricks[collided_brick].setX(-100);
		bricks[collided_brick].setY(-100);
		ball.enablePaddleInterception();
	}
}
