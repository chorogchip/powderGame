#include "Scene_PowderGame.h"

#include "../../main/Game.h"

Scene_PowderGame::Scene_PowderGame() {
  addGui(new Gui_gameoverlay_toolbar());
}

Scene_PowderGame::~Scene_PowderGame() {

}

ch::EnumActionResult Scene_PowderGame::onEvent_key_pressed(sf::Event::KeyEvent evnt, ch::EnumActionResult prev) {

  if (prev != ch::EnumActionResult::SKIPPED) {
    goto END;
  }

  if (evnt.code == sf::Keyboard::Escape) {

    ch::Game::getInstance()->getWorld().pauseWorld();
    addGui(new Gui_ingame_quitworld());
    prev = ch::EnumActionResult::APPLIED;
    goto END;

  } else {
    goto END;
  }


  END:
  return ch::Scene::onEvent_key_pressed(evnt, prev);
}