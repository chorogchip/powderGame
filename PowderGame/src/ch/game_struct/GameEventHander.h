#pragma once

#include <SFML/Graphics.hpp>

#include "../utils/EnumActionResult.h"

#include "SceneEventHandler.h"
#include "WorldEventHandler.h"

namespace ch {

class GameEventHander {

public:
  GameEventHander();
  ~GameEventHander();
  GameEventHander (const GameEventHander&) = delete;
  GameEventHander& operator=(const GameEventHander&) = delete;

  void handleEvent();

private:
  SceneEventHandler scene_event_handler_;
  WorldEventHandler world_event_handler_;


};

}