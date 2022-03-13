#include "GuiComp_Background.h"



namespace ch {

GuiComp_Background::GuiComp_Background(ch::EnumSides side, float xGap, float yGap, float width, float height)
  : GuiComp(side, xGap, yGap, width, height) {

  sf_rect_.setSize(sf::Vector2f(width, height));
  sf_rect_.setFillColor(sf::Color(150, 150, 150));

}

GuiComp_Background::~GuiComp_Background() { }

void GuiComp_Background::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) {
  sf_rect_.setPosition(getTransformedAABB().pos);
  sf_rect_.setSize(getTransformedAABB().size);
}

void GuiComp_Background::render(sf::RenderWindow& window) const {
  window.draw(sf_rect_);
}

}