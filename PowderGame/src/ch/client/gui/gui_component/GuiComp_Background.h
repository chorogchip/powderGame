#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"


namespace ch {

class GuiComp_Background : public GuiComp {

public:

  GuiComp_Background(ch::EnumSides side, int xGap, int yGap, int width, int height);
  ~GuiComp_Background();
  EnumGui3State state_ = EnumGui3State::DEFAULT;


  void render(sf::RenderWindow& window) const override;

private:

  sf::RectangleShape sf_rect_;

  void setTransformedAABB_(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) override;
};

}