#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "EnumActionResult.h"

#include "Gui.h"


namespace ch {


class Scene {

public:
  Scene();
  virtual ~Scene();

  inline void guis_set_TransformedPos_N_Size(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) {
    for (auto o : guis_) {
      o->setTransformedAABB(upper_xPos, upper_yPos, upper_width_scaled, upper_height_scaled, scale);
    }
  }

  inline void addGui(Gui* gui) {
    guis_to_add_.push_back(gui);
  }

  virtual ch::EnumActionResult onEvent_mouse_entered(ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_mouse_left(ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_text_entered(sf::Event::TextEvent evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_key_pressed(sf::Event::KeyEvent evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_key_released(sf::Event::KeyEvent evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_mouse_wheel_scrolled(sf::Event::MouseWheelScrollEvent evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_mouse_button_pressed(sf::Event::MouseButtonEvent evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_mouse_button_released(sf::Event::MouseButtonEvent evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_mouse_moved(sf::Event::MouseMoveEvent evnt, ch::EnumActionResult prev);
  virtual void update();
  virtual void render();

private:

  std::vector<Gui*> guis_;
  std::vector<Gui*> guis_to_add_;

  friend class SceneEventHandler;
  friend class SceneUpdater;
  friend class SceneRenderer;

};

}