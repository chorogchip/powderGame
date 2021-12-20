#pragma once

#include <SFML/Graphics.hpp>
#include "EnumSides.h"
#include "sfAABB.h"

class Button {
public:
	Button(EnumSides side_, int xGap_, int yGap_, int width_, int height_);
	~Button();
	EnumSides side;
	int xGap, yGap;
	int width, height;
	sfAABB aabb;

	sf::Text text;
	EnumSides textSide;
	bool toRenderText;

	sf::Sprite sprite;

};
