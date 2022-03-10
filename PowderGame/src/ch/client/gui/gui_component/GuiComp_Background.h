#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"

namespace ch {
class GuiComp_Background : public GuiComp {

public:

  GuiComp_Background(ch::EnumSides side, float xGap, float yGap, float width, float height);
  ~GuiComp_Background();
  EnumGui3State state_ = EnumGui3State::DEFAULT;


  void render(sf::RenderWindow& window) const override;

private:

  sf::RectangleShape sf_rect_;

  void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) override;

};}