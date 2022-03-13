#include "World.h"

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

  return ch::EnumActionResult::SUCCEED;
}

void World::update() {
  if(is_world_paused_) {
    return;
  }
}

}