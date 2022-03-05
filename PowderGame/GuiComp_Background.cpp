#include "GuiComp_Background.h"



namespace ch {

GuiComp_Background::GuiComp_Background(ch::EnumSides side, int xGap, int yGap, int width, int height)
  : GuiComponent(side, xGap, yGap, width, height) {

  sf_rect_.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
  sf_rect_.setFillColor(sf::Color(150, 150, 150));

}

GuiComp_Background::~GuiComp_Background() { }

void GuiComp_Background::setTransformedAABB_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) {
  sf_rect_.setPosition(getTransformedAABB().pos);
  sf_rect_.setScale(sf::Vector2f(GUI_scale, GUI_scale));
}

void GuiComp_Background::render(sf::RenderWindow& window) const {
  window.draw(sf_rect_);
}

}