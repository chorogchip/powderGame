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
  inline void pauseWorld() { is_world_paused_ = true; }
  inline void continueWorld() { is_world_paused_ = false; }
  inline bool isWorldPaused() const { return is_world_paused_; }

private:
  bool is_world_paused_ = false;

  const int map_x_;
  const int map_y_;

  std::vector<Tile> map_;
};
} // namespace ch
