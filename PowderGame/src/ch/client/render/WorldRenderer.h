#pragma once

#include "../../world/World.h"

namespace ch {


class WorldRenderer {
public:
	WorldRenderer();
	~WorldRenderer();

	void render(World& world);
};

}