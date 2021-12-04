#include "Interceptor.h"

void Interceptor::ball_paddle_collision(Ball& ball, Paddle& paddle)
{
	if (ball.getYCenter() + ball.getRadius() >= paddle.getY() && (
		(ball.getXCenter() + ball.getRadius() >= paddle.getX() &&
			ball.getXCenter() + ball.getRadius() <= paddle.getX() + paddle.width) ||
		(ball.getXCenter() - ball.getRadius() <= paddle.getX() + paddle.width &&
			ball.getXCenter() - ball.getRadius() >= paddle.getX()))) {
			ball.bounceV(((ball.getXCenter() - (paddle.getX() + paddle.width / 2))*0.0025f) / (paddle.width / 2), paddle.getX());
	}
}

void Interceptor::ball_wall_collision(Ball& ball, int left_limit, int bottom_limit, int right_limit, int upper_limit) const {
	if (ball.getXCenter() + ball.getRadius() >= right_limit) {
		ball.setXCenter(right_limit - ball.getRadius());
		ball.invertXSpeed();
		ball.enablePaddleInterception();
	}
	if (ball.getYCenter() + ball.getRadius() >= bottom_limit) {
		ball.setYCenter(bottom_limit - ball.getRadius());
		ball.invertYSpeed();
		ball.enablePaddleInterception();
	}
	if (ball.getXCenter() - ball.getRadius() <= left_limit) {
		ball.setXCenter(left_limit + ball.getRadius());
		ball.invertXSpeed();
		ball.enablePaddleInterception();
	}
	if (ball.getYCenter() - ball.getRadius() <= upper_limit) {
		ball.setYCenter(upper_limit + ball.getRadius());
		ball.invertYSpeed();
		ball.enablePaddleInterception();
	}
}