#pragma once

#include <vector>

#include "../main/Reference.h"
#include "../utils/EnumActionResult.h"

#include "../../game_features/tile/Tile.h"

namespace ch {
class World {

public:

	World(int mapX, int mapY);
	~World();

	ch::EnumActionResult init();
	void update();

private:

	const int map_x_;
	const int map_y_;

	Tile* map_;

};}

