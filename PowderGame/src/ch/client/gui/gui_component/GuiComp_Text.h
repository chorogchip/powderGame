#pragma once

#include <string>

#include <SFML/Graphics.hpp>

#include "EnumGui3State.h"

#include "GuiComponent.h"



namespace ch {


class GuiComp_Text : public GuiComponent {

public:

  GuiComp_Text(ch::EnumSides side, int xGap, int yGap, int width, int height, std::wstring text, int text_size);
  ~GuiComp_Text();

  sf::Text text_;
  const int text_size_;

  void render(sf::RenderWindow& window) const override;

private:

  void setTransformedAABB_(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) override;
};

}