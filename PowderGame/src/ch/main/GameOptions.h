#pragma once

#include <SFML/Graphics.hpp>

namespace ch {

enum class EnumHoldingComponent {
  NOTHING,
  BACKGROUND,
  BUTTON,
  BAR,
  MOVEBAR,
  TEXTBOX,
};

struct GameOptions {

  GameOptions(int winX, int winY): last_window_size(sf::Vector2i(winX, winY)) {}

  bool is_full_screen = false;
  bool is_mouse_inside = true;
  bool is_in_focus = true;
  sf::Vector2i clicked_pos;
  sf::Vector2i last_window_size;
  EnumHoldingComponent holding_component = EnumHoldingComponent::NOTHING;

};

}