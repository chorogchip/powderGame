#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumSides.h"
#include "../../../utils/AABB.h"
#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"


namespace ch {
class GuiComp_Bar : public GuiComp {

public:

  GuiComp_Bar(ch::EnumSides side, float xGap, float yGap, float width, float height, int gauge_max, int gauge_current);
  ~GuiComp_Bar();


  EnumGui3State state_ = EnumGui3State::DEFAULT;
  inline int getGaugeMax() const {
    return gauge_max_;
  }
  inline int getGaugeCurrent() const {
    return gauge_current_;
  }
  void setGaugeCurrent(int gauge);
  inline ch::sfAABB getBarCollisionBox() const {
    return ch::sfAABB(sf::Vector2f(getTransformedAABB().pos.x + getTransformedAABB().size.y * (7.0f / 16.0f),
                                   getTransformedAABB().pos.y + getTransformedAABB().size.y * (6.0f / 16.0f)),
                      sf::Vector2f(getTransformedAABB().size.x - getTransformedAABB().size.y * (14.0f / 16.0f),
                                   getTransformedAABB().size.y * (4.0f / 16.0f)));
  }
  inline ch::sfAABB getBarHandleCollisionBox() const {
    return ch::sfAABB(sf::Vector2f(transformedPos_handle_.x + getTransformedAABB().size.y * (4.0f / 16.0f),
                                   transformedPos_handle_.y + getTransformedAABB().size.y * (5.0f / 16.0f)),
                      sf::Vector2f(getTransformedAABB().size.y * (8.0f / 16.0f),
                                   getTransformedAABB().size.y * (6.0f / 16.0f)));
  }

  void render(sf::RenderWindow& winddow) const override;

private:

  sf::Sprite sf_sprite_[3];
  sf::Sprite sf_sprite_handle_[3];
  sf::Vector2f transformedPos_handle_;

  int gauge_current_;
  const int gauge_max_;


  void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) override;

};}