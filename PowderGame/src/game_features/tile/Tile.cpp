#include "Tile.h"

Tile::Tile(): kind_(EnumTile::NOTING) { }
Tile::Tile(EnumTile kind): kind_(kind) { }
Tile::~Tile() { }

bool Tile::isSameTile(const Tile& tile) {
  return kind_ == tile.kind_;
}
bool Tile::isSameKind(const Tile& tile) {



  return kind_ == tile.kind_;
}