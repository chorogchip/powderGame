#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "../utils/EnumActionResult.h"

#include "../client/gui/Gui.h"


namespace ch {


class Scene {

public:
  Scene();
  virtual ~Scene();
  Scene (const Scene&) = delete;
  Scene& operator=(const Scene&) = delete;

  inline void guis_set_TransformedPos_N_Size(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {
    for (auto o : guis_) {
      o->setTransformedAABB(upper_xPos, upper_yPos, upper_width_scaled, upper_height_scaled, scale);
    }
  }

  inline void addGui(Gui* gui) {
    guis_to_add_.push_back(gui);
  }

  // when you override, you should call this function at the end if you don't wa to modify original.
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
  virtual void render() const;

private:

  std::vector<Gui*> guis_;
  std::vector<Gui*> guis_to_add_;

  friend class SceneEventHandler;
  friend class SceneUpdater;
  friend class SceneRenderer;

};

}