#pragma once

enum class EnumTile : unsigned char {
  
  NOTING,

  ICE,
  WATER,
  STEAM,
  SALT_WATER,
  SULFUR,
  OIL,

  SAND,
  SALT,
  SPROUT,
  NITROGLICERIN,

  PLANT,
  WOOD,
  COAL,
  STONE,
  CONCRETE,
  STEEL,
  DIAMOND,

  FIRE,
  TORCH,
  LAVA,

  SIZE,

};

class Tile {

public:

  Tile();
  Tile(EnumTile kind);
  ~Tile();

  bool isSameTile(const Tile& tile);
  bool isSameKind(const Tile& tile);

private:

  EnumTile kind_;
  signed char speed_x_ = 0;
  signed char speed_y_ = 0;
  unsigned char decreased_durability_ = 0;

};

