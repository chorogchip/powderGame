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

ch::EnumActionResult Scene_PowderGame::onEvent_mouse_wheel_scrolled(sf::Event::MouseWheelScrollEvent evnt, ch::EnumActionResult prev) {
  float* zz;
  if (prev != ch::EnumActionResult::SKIPPED) {
    goto END;
  }

  zz = &ch::Game::getInstance()->getRenderstate().cam_zoom;
  if (evnt.delta != 0) {
    if(*zz >= 128) {
      *zz += evnt.delta * 64.0f;
    }
    if(*zz >= 64.0f) {
      *zz += evnt.delta * 16.0f;
    }
    if(*zz >= 32.0f) {
      *zz += evnt.delta * 4.0f;
    } else {
      *zz += evnt.delta;
    }
    prev = ch::EnumActionResult::APPLIED;
  }

  if(*zz < 4.0f) {
    *zz = 4.0f;
  }
  if(*zz > 256.0f) {
    *zz = 256.0f;
  }

  END:
  return ch::Scene::onEvent_mouse_wheel_scrolled(evnt, prev);
}

void Scene_PowderGame::update() {

  const float spd_str = 4.0f * ch::Game::getInstance()->getRenderstate().cam_zoom;
  const float spd_dag = spd_str / 1.4142135623730950488016887242097f;  // sqrt 2. why sqrt is not constexpr???

  bool w = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  bool s = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  bool a = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  bool d = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

  if (w && s) {
    if (is_pkw) {
      if (a && d)
        if (is_pka) { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, spd_dag); }
        else        { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, spd_dag); }
      else if (a)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, spd_dag); is_pka = true; }
      else if (d)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, spd_dag); is_pka = false; }
      else          { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(    0.0f, spd_str); }
    } else {
      if (a && d)
        if (is_pka) { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, -spd_dag); }
        else        { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, -spd_dag); }
      else if (a)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, -spd_dag); is_pka = true; }
      else if (d)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, -spd_dag); is_pka = false; }
      else          { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(    0.0f, -spd_str); }
    }
  } else if (w) {
    is_pkw = true;
    if (a && d)
      if (is_pka) { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, -spd_dag); }
      else        { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, -spd_dag); }
    else if (a)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, -spd_dag); is_pka = true; }
    else if (d)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, -spd_dag); is_pka = false; }
    else          { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(    0.0f, -spd_str); }
  } else if (s) {
    is_pkw = false;
    if (a && d)
      if (is_pka) { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, spd_dag); }
      else        { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, spd_dag); }
    else if (a)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_dag, spd_dag); is_pka = true; }
    else if (d)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_dag, spd_dag); is_pka = false; }
    else          { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(    0.0f, spd_str); }
  } else {
    if (a && d)
      if (is_pka) { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_str, 0.0f); }
      else        { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_str, 0.0f); }
    else if (a)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f(-spd_str, 0.0f); is_pka = true; }
    else if (d)   { ch::Game::getInstance()->getRenderstate().cam_pos += sf::Vector2f( spd_str, 0.0f); is_pka = false; }
    else          {}
  }
  
  ch::Scene::update();
}