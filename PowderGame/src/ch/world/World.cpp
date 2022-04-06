#include "World.h"

// юс╫ц
#include <random>


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
  
  map_.assign(map_x_ * map_y_, Tile(
    static_cast<EnumTile>(rand() % static_cast<int>(EnumTile::SIZE))));
  
  return ch::EnumActionResult::SUCCEED;
}

void World::update() {
  if(is_world_paused_) {
    return;
  }
}


constexpr sf::Color World::getTileColor(EnumTile kind) {
  switch(kind) {

  case EnumTile::NOTING: return sf::Color(0, 0, 0);

  case EnumTile::ICE: return sf::Color(0, 100, 0);
  case EnumTile::WATER: return sf::Color(0, 100, 0);
  case EnumTile::STEAM: return sf::Color(0, 100, 0);
  case EnumTile::SALT_WATER: return sf::Color(0, 100, 0);
  case EnumTile::SULFUR: return sf::Color(100, 0, 100);
  case EnumTile::OIL: return sf::Color(0, 100, 100);

  case EnumTile::SAND: return sf::Color(0, 0, 0);
  case EnumTile::SALT: return sf::Color(100, 0, 100);
  case EnumTile::SPROUT: return sf::Color(0, 0, 0);
  case EnumTile::NITROGLICERIN: return sf::Color(0, 0, 0);

  case EnumTile::PLANT: return sf::Color(0, 0, 0);
  case EnumTile::WOOD: return sf::Color(100, 100, 0);
  case EnumTile::COAL: return sf::Color(100, 100, 0);
  case EnumTile::STONE: return sf::Color(0, 0, 0);
  case EnumTile::CONCRETE: return sf::Color(0, 100, 0);
  case EnumTile::STEEL: return sf::Color(0, 100, 0);
  case EnumTile::DIAMOND: return sf::Color(0, 0, 100);

  case EnumTile::FIRE: return sf::Color(0, 0, 0);
  case EnumTile::TORCH: return sf::Color(0, 0, 0);
  case EnumTile::LAVA: return sf::Color(0, 0, 0);

  case EnumTile::SIZE: return sf::Color(0, 0, 0);

  }
}

}