#include "Tile.h"

Tile::Tile() {

}

Tile::~Tile() { }


bool Tile::isSameTile(const Tile& tile) {
  return kind_ == tile.kind_;
}
bool Tile::isSameKind(const Tile& tile) {



  return kind_ == tile.kind_;
}