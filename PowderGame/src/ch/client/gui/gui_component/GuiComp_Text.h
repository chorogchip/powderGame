#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"



namespace ch {
class GuiComp_Text : public GuiComp {

public:

  GuiComp_Text(ch::EnumSides side, float xGap, float yGap, float width, float height, std::wstring text, float text_size);
  ~GuiComp_Text();

  void render(sf::RenderWindow& window) const override;

  inline sf::FloatRect getTextLocalBounds() const {
    return text_.getLocalBounds();
  }

private:

  sf::Text text_;
  const float text_size_;
  bool resized_text_size_ = false;
  void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) override;

};}