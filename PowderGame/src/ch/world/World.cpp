#include "World.h"

// юс╫ц
#include <random>
#include <time.h>


namespace ch {

World::World(int mapX, int mapY): map_x_(mapX), map_y_(mapY) {

}


World::~World() {

}

ch::EnumActionResult World::init() {
  if (map_x_ <= 0) {
    return ch::EnumActionResult::FAILED;
  } else if (map_y_ <= 0) {
    return ch::EnumActionResult::FAILED;
  }
  
  map_.assign(map_x_ * map_y_, Tile());
  for(auto& o : map_) {
    o = Tile(static_cast<EnumTile>(rand() % static_cast<int>(EnumTile::SIZE)));
  }

  return ch::EnumActionResult::SUCCEED;
}

void World::update() {
  if(is_world_paused_) {
    return;
  }

  for (int i = map_y_ - 1; i > 0; --i)
    for (int j = 0; j != map_x_; ++j)
      map_[i * map_x_ + j] = map_[(i - 1) * map_x_ + j];
  for (int j = 0; j != map_x_; ++j)
    map_[j] = Tile(static_cast<EnumTile>(rand() % static_cast<int>(EnumTile::SIZE)));
 

}

bool World::isValidPos(sf::Vector2i pos) const {
  if (pos.x < 0 || pos.y < 0 || pos.x >= map_x_ || pos.y >= map_y_) return false;
  else return true;
}

Tile& World::getTile(sf::Vector2i pos) {
  return map_[pos.y * map_x_ + pos.x];
}

}  // namespace ch