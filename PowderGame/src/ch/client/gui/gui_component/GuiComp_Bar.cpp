#include "GuiComp_Bar.h"

#include "../../../main/Game.h"


namespace ch {

GuiComp_Bar::GuiComp_Bar(ch::EnumSides side, int xGap, int yGap, int width, int height,
                         int gauge_max, int gauge_current)
  : GuiComp(side, xGap, yGap, width, height), gauge_max_(gauge_max), gauge_current_(gauge_current) {

  setGaugeCurrent(gauge_current_);
  Game::getInstance()->getTextureLoader().setTexture_Bar(sf_sprite_[0], sf_sprite_[1], sf_sprite_[2], sf_sprite_handle_[0], sf_sprite_handle_[1], sf_sprite_handle_[2], width, height);
}

GuiComp_Bar::~GuiComp_Bar() {

}

int GuiComp_Bar::getGaugeCurrent() const {
  return gauge_current_;
}

void GuiComp_Bar::setGaugeCurrent(int gauge) {
  gauge_current_ = gauge;
  if (gauge_current_ < 0) {
    gauge_current_ = 0;
  } else if (gauge_current_ > gauge_max_) {
    gauge_current_ = gauge_max_;
  }
  sf_sprite_[2].setTextureRect(sf::IntRect(0, 0, (get_height() >> 1) + (get_width() - get_height()) * gauge_current_ / gauge_max_, get_height()));

  transformedPos_handle_ = sf::Vector2f(getTransformedAABB().pos.x + (getTransformedAABB().size.x - getTransformedAABB().size.y) * static_cast<float>(gauge_current_) / static_cast<float>(gauge_max_), getTransformedAABB().pos.y);
  sf_sprite_handle_[0].setPosition(transformedPos_handle_);
  sf_sprite_handle_[1].setPosition(transformedPos_handle_);
  sf_sprite_handle_[2].setPosition(transformedPos_handle_);
}

void GuiComp_Bar::setTransformedAABB_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) {
  sf_sprite_[0].setPosition(getTransformedAABB().pos);
  sf_sprite_[1].setPosition(getTransformedAABB().pos);
  sf_sprite_[2].setPosition(getTransformedAABB().pos);
  sf_sprite_[0].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_[1].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_[2].setScale(sf::Vector2f(GUI_scale, GUI_scale));

  transformedPos_handle_ = sf::Vector2f(getTransformedAABB().pos.x + (getTransformedAABB().size.x - getTransformedAABB().size.y) * static_cast<float>(gauge_current_) / static_cast<float>(gauge_max_), getTransformedAABB().pos.y);
  sf_sprite_handle_[0].setPosition(transformedPos_handle_);
  sf_sprite_handle_[1].setPosition(transformedPos_handle_);
  sf_sprite_handle_[2].setPosition(transformedPos_handle_);
  sf_sprite_handle_[0].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_handle_[1].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_handle_[2].setScale(sf::Vector2f(GUI_scale, GUI_scale));
}

void GuiComp_Bar::render(sf::RenderWindow& window) const {
  if (state_ == EnumGui3State::PRESSED) {
    window.draw(sf_sprite_[static_cast<int>(EnumGui3State::MOUSE_ON)]);
  } else {
    window.draw(sf_sprite_[static_cast<int>(state_)]);
  }
  window.draw(sf_sprite_[static_cast<int>(EnumGui3State::PRESSED)]);
  window.draw(sf_sprite_handle_[static_cast<int>(state_)]);
}

}