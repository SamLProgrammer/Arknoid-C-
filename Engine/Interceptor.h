#pragma once
#include "Ball.h"
#include "Paddle.h"

class Interceptor {
public:
	void ball_paddle_collision(Ball& ball, Paddle&  paddle);
	void Interceptor::ball_wall_collision(Ball& ball, int left_limit, int bottom_limit, int right_limit, int upper_limit) const;
private:
};