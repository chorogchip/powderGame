#pragma once

#include <SFML/Graphics.hpp>

#include "GuiComp.h"

namespace ch {
class GuiComp_Sprite : public GuiComp {

public:

  GuiComp_Sprite(ch::EnumSides side, float xGap, float yGap, float width, float height);
  ~GuiComp_Sprite();

  void setTexture(const sf::Texture& t);
  void render(sf::RenderWindow& window) const override;
  inline void setToRender(bool to_render) {
    to_render_ = to_render;
  }

private:
  
  bool to_render_ = true;
  sf::Sprite spr_;
  void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) override;

};}