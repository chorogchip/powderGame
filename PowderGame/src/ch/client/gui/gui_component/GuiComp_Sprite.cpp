#include "GuiComp_Sprite.h"

namespace ch {
  
GuiComp_Sprite::GuiComp_Sprite(ch::EnumSides side, float xGap, float yGap, float width, float height)
  : GuiComp(side, xGap, yGap, width, height) {

}

GuiComp_Sprite::~GuiComp_Sprite() { }

void GuiComp_Sprite::setTexture(const sf::Texture& t) {
  spr_.setTexture(t);
}

void GuiComp_Sprite::render(sf::RenderWindow& window) const {
  if(to_render_) {
    window.draw(spr_);
  }
}

void GuiComp_Sprite::setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {
  spr_.setPosition(getTransformedAABB().pos);
  spr_.setScale(sf::Vector2f(scale, scale));
}

}