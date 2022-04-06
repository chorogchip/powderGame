#pragma once

#include "../../world/World.h"

namespace ch {


class WorldRenderer {
public:
	WorldRenderer();
	~WorldRenderer();
	WorldRenderer (const WorldRenderer&) = delete;
	WorldRenderer& operator=(const WorldRenderer&) = delete;

	void render(World& world);

private:
};

}