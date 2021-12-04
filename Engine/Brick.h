#pragma once
#include "Vec2DF.h"
#include "Colors.h"
#include "Graphics.h"
class Brick {
public:
	Brick() = default;
	Brick(Vec2DF& position, float width, float height, Color in_c);
	bool operator==(Vec2DF& rh_vec);
	void draw(Graphics& gfx);
private:
	Color c;
	Vec2DF position;
	float width;
	float height;
};