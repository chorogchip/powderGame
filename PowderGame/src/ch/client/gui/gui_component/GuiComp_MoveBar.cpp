#include "GuiComp_MoveBar.h"

#include "../../../main/Game.h"



namespace ch {

GuiComp_MoveBar::GuiComp_MoveBar(ch::EnumSides side, float xGap, float yGap, float width, float height)
  : GuiComp(side, xGap, yGap, width, height) {


  Game::getInstance()->getTextureLoader().setTexture_Movebar(sf_sprite_[0], sf_sprite_[1], sf_sprite_[2], static_cast<int>(width), static_cast<int>(height));
}

GuiComp_MoveBar::~GuiComp_MoveBar() { }

void GuiComp_MoveBar::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) {
  auto& pos = getTransformedAABB().pos;
  sf_sprite_[0].setPosition(pos);
  sf_sprite_[1].setPosition(pos);
  sf_sprite_[2].setPosition(pos);
  auto vect = sf::Vector2f(GUI_scale, GUI_scale);
  sf_sprite_[0].setScale(vect);
  sf_sprite_[1].setScale(vect);
  sf_sprite_[2].setScale(vect);
}

void GuiComp_MoveBar::render(sf::RenderWindow& window) const {
  window.draw(sf_sprite_[static_cast<int>(state_)]);
}

}