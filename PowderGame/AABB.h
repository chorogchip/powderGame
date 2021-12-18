#pragma once

struct AABB {
	int x, y, w, h;

	AABB(int xPos, int yPos, int width, int height) :
		x(xPos), y(yPos), w(width), h(height) {}
};