#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumSides.h"
#include "../../../utils/AABB.h"
#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"


namespace ch {

class GuiComp_Bar : public GuiComp {

public:

  GuiComp_Bar(ch::EnumSides side, int xGap, int yGap, int width, int height, int gauge_max, int gauge_current);
  ~GuiComp_Bar();


  EnumGui3State state_ = EnumGui3State::DEFAULT;
  const int gauge_max_;
  int getGaugeCurrent() const;
  void setGaugeCurrent(int gauge);
  inline ch::sfAABB getBarCollisionBox() const {
    return ch::sfAABB(sf::Vector2f(getTransformedAABB().pos.x + getTransformedAABB().size.y * 7 / 16,
                                   getTransformedAABB().pos.y + getTransformedAABB().size.y * 6 / 16),
                      sf::Vector2f(getTransformedAABB().size.x - getTransformedAABB().size.y * 14 / 16,
                                   getTransformedAABB().size.y * 4 / 16));
  }
  inline ch::sfAABB getBarHandleCollisionBox() const {
    return ch::sfAABB(sf::Vector2f(transformedPos_handle_.x + getTransformedAABB().size.y * 4 / 16,
                                   transformedPos_handle_.y + getTransformedAABB().size.y * 5 / 16),
                      sf::Vector2f(getTransformedAABB().size.y * 8 / 16,
                                   getTransformedAABB().size.y * 6 / 16));
  }

  void render(sf::RenderWindow& winddow) const override;

private:


  sf::Sprite sf_sprite_[3];
  sf::Sprite sf_sprite_handle_[3];
  int gauge_current_;
  sf::Vector2f transformedPos_handle_;


  void setTransformedAABB_(int upper_xPos, int upper_yPos,
                                  int upper_width_scaled,
                                  int upper_height_scaled,
                                  float scale) override;
};


}