#include "GuiComp_Bar.h"

#include "../../../main/Game.h"


namespace ch {

GuiComp_Bar::GuiComp_Bar(ch::EnumSides side, float xGap, float yGap, float width, float height,
                         int gauge_max, int gauge_current)
  : GuiComp(side, xGap, yGap, width, height), gauge_max_(gauge_max), gauge_current_(gauge_current) {

  setGaugeCurrent(gauge_current_);
  Game::getInstance()->getTextureLoader().setTexture_Bar(sf_sprite_[0], sf_sprite_[1], sf_sprite_[2], sf_sprite_handle_[0], sf_sprite_handle_[1], sf_sprite_handle_[2], static_cast<int>(width), static_cast<int>(height));
}

GuiComp_Bar::~GuiComp_Bar() {

}

inline void GuiComp_Bar::setGaugeCurrent(int gauge) {
  gauge_current_ = gauge;
  if (gauge_current_ < 0) {
    gauge_current_ = 0;
  } else if (gauge_current_ > gauge_max_) {
    gauge_current_ = gauge_max_;
  }
  sf_sprite_[2].setTextureRect(sf::IntRect(0, 0,
                                           static_cast<int>((get_height() / 2.0f) + (get_width() - get_height()) * static_cast<float>(gauge_current_) / static_cast<float>(gauge_max_)),
                                           static_cast<int>(get_height())
  ));

  transformedPos_handle_ = sf::Vector2f(getTransformedAABB().pos.x + (getTransformedAABB().size.x - getTransformedAABB().size.y) * static_cast<float>(gauge_current_) / static_cast<float>(gauge_max_), getTransformedAABB().pos.y);
  sf_sprite_handle_[0].setPosition(transformedPos_handle_);
  sf_sprite_handle_[1].setPosition(transformedPos_handle_);
  sf_sprite_handle_[2].setPosition(transformedPos_handle_);
}

void GuiComp_Bar::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) {
  auto& pos = getTransformedAABB().pos;
  sf_sprite_[0].setPosition(pos);
  sf_sprite_[1].setPosition(pos);
  sf_sprite_[2].setPosition(pos);
  auto vect = sf::Vector2f(GUI_scale, GUI_scale);
  sf_sprite_[0].setScale(vect);
  sf_sprite_[1].setScale(vect);
  sf_sprite_[2].setScale(vect);

  transformedPos_handle_ = sf::Vector2f(pos.x + (getTransformedAABB().size.x - getTransformedAABB().size.y) * gauge_current_ / gauge_max_, pos.y);
  sf_sprite_handle_[0].setPosition(transformedPos_handle_);
  sf_sprite_handle_[1].setPosition(transformedPos_handle_);
  sf_sprite_handle_[2].setPosition(transformedPos_handle_);
  sf_sprite_handle_[0].setScale(vect);
  sf_sprite_handle_[1].setScale(vect);
  sf_sprite_handle_[2].setScale(vect);
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