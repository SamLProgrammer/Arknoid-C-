#pragma once
#include "Vec2DF.h"
#include "Colors.h"
class Brick {
public:
	Brick(Vec2DF& position, Color in_c);
	bool operator==(Vec2DF& rh_vec);
private:
	Color c;
	Vec2DF position;
	float width = 40.0f;
	float height = 15.0f;
};