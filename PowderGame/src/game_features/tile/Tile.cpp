#include "Tile.h"

Tile::Tile(): kind_(EnumTile::NOTING) { }
Tile::Tile(EnumTile kind): kind_(kind) { }
Tile::~Tile() { }

sf::Color Tile::getTileColor() const {
  switch(kind_) {

  case EnumTile::NOTING: case EnumTile::SIZE: default: return sf::Color(0, 0, 0);

  case EnumTile::ICE: return sf::Color(30, 100, 0);
  case EnumTile::WATER: return sf::Color(50, 100, 0);
  case EnumTile::STEAM: return sf::Color(70, 100, 0);
  case EnumTile::SALT_WATER: return sf::Color(0, 100, 30);
  case EnumTile::SULFUR: return sf::Color(100, 10, 100);
  case EnumTile::OIL: return sf::Color(0, 100, 100);

  case EnumTile::SAND: return sf::Color(70, 50, 50);
  case EnumTile::SALT: return sf::Color(100, 0, 100);
  case EnumTile::SPROUT: return sf::Color(60, 60, 30);
  case EnumTile::NITROGLICERIN: return sf::Color(70, 30, 20);

  case EnumTile::PLANT: return sf::Color(10, 50, 20);
  case EnumTile::WOOD: return sf::Color(100, 100, 0);
  case EnumTile::COAL: return sf::Color(100, 100, 0);
  case EnumTile::STONE: return sf::Color(0, 10, 50);
  case EnumTile::CONCRETE: return sf::Color(0, 100, 0);
  case EnumTile::STEEL: return sf::Color(10, 100, 0);
  case EnumTile::DIAMOND: return sf::Color(10, 0, 100);

  case EnumTile::FIRE: return sf::Color(20, 50, 0);
  case EnumTile::TORCH: return sf::Color(50, 0, 0);
  case EnumTile::LAVA: return sf::Color(100, 0, 0);

  }
}

bool Tile::isSameTile(const Tile& tile) {
  return kind_ == tile.kind_;
}
bool Tile::isSameKind(const Tile& tile) {

  return kind_ == tile.kind_;
}