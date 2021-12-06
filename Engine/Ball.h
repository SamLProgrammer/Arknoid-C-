#pragma once
#include "Vec2DF.h"
#include "Graphics.h"

class Ball {
public:
	Ball(Vec2DF& in_position, Vec2DF& in_speed);
	void move(float dt);
	void draw(Graphics& gfx);
	float getXCenter();
	float getYCenter();
	float getRadius() const;
	void setXCenter(float x_center);
	void setYCenter(float y_center);
	void invertXSpeed();
	void invertYSpeed();
	void bounceV(float slope, float paddle_x);
	void enablePaddleInterception();
	void disablePaddleInterception();
	static constexpr float radius = 7.5f;
	float speed_factor = 4.0f;
	void slow();
	void fast();
private:
	bool paddle_interception = true;
	Vec2DF position;
	Vec2DF speed;
};

