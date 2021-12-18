#pragma once
#include "World.h"

class WorldRenderer {
public:
	WorldRenderer();
	~WorldRenderer();

	void render(World& world);
};

