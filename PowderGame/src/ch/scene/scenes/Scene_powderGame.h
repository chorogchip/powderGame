#pragma once

#include "../Scene.h"

#include "../../client/gui/guis/ingame/Gui_gameoverlay_toolbar.h"
#include "../../client/gui/guis/ingame/Gui_ingame_quitworld.h"

class Scene_PowderGame : public ch::Scene {

public:

  Scene_PowderGame();
  ~Scene_PowderGame();

  ch::EnumActionResult onEvent_key_pressed(sf::Event::KeyEvent evnt, ch::EnumActionResult prev) override;
  ch::EnumActionResult onEvent_mouse_wheel_scrolled(sf::Event::MouseWheelScrollEvent evnt, ch::EnumActionResult prev) override;
  void update() override;

private:
  bool is_pkw = true;  // is previous pressed key is w, not s
  bool is_pka = true;  // is previous pressed key is a, not d


};

