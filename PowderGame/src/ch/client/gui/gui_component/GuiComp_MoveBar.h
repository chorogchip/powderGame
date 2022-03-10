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

  GuiComp_MoveBar(ch::EnumSides side, float xGap, float yGap, float width, float height);
  ~GuiComp_MoveBar();
  EnumGui3State state_ = EnumGui3State::DEFAULT;

  void render(sf::RenderWindow& window) const override;

private:

  sf::Sprite sf_sprite_[3];

  void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) override;
};

}