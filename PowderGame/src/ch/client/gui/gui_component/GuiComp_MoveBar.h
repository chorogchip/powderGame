#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"


namespace ch {


enum class EnumMouveBarStates : int {
  DEFAULT = 0,
  MOUSE_ON = 1,
  PRESSED = 2,
};

class GuiComp_MoveBar : public GuiComp {

public:

  GuiComp_MoveBar(ch::EnumSides side, int xGap, int yGap, int width, int height);
  ~GuiComp_MoveBar();
  EnumGui3State state_ = EnumGui3State::DEFAULT;

  void render(sf::RenderWindow& window) const override;

private:

  sf::Sprite sf_sprite_[3];

  void setTransformedAABB_(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) override;
};

}