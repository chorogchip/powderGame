#pragma once

#include "../Scene.h"

#include "../../client/gui/guis/ingame/Gui_gameoverlay_toolbar.h"
#include "../../client/gui/guis/ingame/Gui_ingame_quitworld.h"

class Scene_PowderGame : public ch::Scene {

public:

  Scene_PowderGame();
  ~Scene_PowderGame();

  ch::EnumActionResult onEvent_key_pressed(sf::Event::KeyEvent evnt, ch::EnumActionResult prev) override;

private:


};

