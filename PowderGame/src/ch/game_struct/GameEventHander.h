#pragma once

#include <SFML/Graphics.hpp>

#include "EnumActionResult.h"

#include "SceneEventHandler.h"
#include "WorldEventHandler.h"

namespace ch {

class GameEventHander {

public:
  GameEventHander();
  ~GameEventHander();
  void handleEvent();

private:
  SceneEventHandler scene_event_handler_;
  WorldEventHandler world_event_handler_;


};

}