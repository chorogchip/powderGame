#pragma once

enum class EnumTile {
  
  NOTING,

  AIR,


};

class Tile {

public:

  Tile();
  ~Tile();

  bool isSameTile(const Tile& tile);
  bool isSameKind(const Tile& tile);

private:

  EnumTile kind_ = EnumTile::NOTING;

};

