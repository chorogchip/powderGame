#include "Scene.h"
#include "../main/Game.h"



namespace ch {


Scene::Scene() { }

Scene::~Scene() {
  for (auto it = guis_.rbegin(); it != guis_.rend(); it++) {
    delete* it;
  }
  for (auto it = guis_to_add_.rbegin(); it != guis_to_add_.rend(); it++) {
    delete* it;
  }
}

ch::EnumActionResult Scene::onEvent_mouse_entered(ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_mouse_left(ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_text_entered(sf::Event::TextEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_key_pressed(sf::Event::KeyEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_key_released(sf::Event::KeyEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_mouse_wheel_scrolled(sf::Event::MouseWheelScrollEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_mouse_button_pressed(sf::Event::MouseButtonEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_mouse_button_released(sf::Event::MouseButtonEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

ch::EnumActionResult Scene::onEvent_mouse_moved(sf::Event::MouseMoveEvent evnt, ch::EnumActionResult prev) {
  return prev;
}

void Scene::update() {
  for (auto it = guis_.end(); it != guis_.begin();) {
    it--;
    if ((*it)->isToClose()) {
      delete* it;
      it = guis_.erase(it);
    }
  }
  for (auto o : guis_to_add_) {
    auto vect = Game::getInstance()->getWindow().getSize();
    o->setTransformedAABB(0, 0, static_cast<int>(vect.x), static_cast<int>(vect.y), Game::getInstance()->getRenderstate().ui_scale);
    guis_.push_back(o);
  }
  guis_to_add_.clear();
}

void Scene::render() {

}


}