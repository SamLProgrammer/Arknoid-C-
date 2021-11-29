#include "FrameTimer.h"

FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::mark()
{
	std::chrono::steady_clock::time_point actual = std::chrono::steady_clock::now();
	std::chrono::duration<float> delta = actual - last;
	last = actual;
	return delta.count();
}

