#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"
#include "GuiComp_Text.h"

namespace ch {
class GuiComp_TextHolder : public GuiComp {

public:

  GuiComp_TextHolder(ch::EnumSides side, float xGap, float yGap, float width, float height, ch::EnumSides text_side, std::wstring text_text, float text_size);
  ~GuiComp_TextHolder();

  void render(sf::RenderWindow& window) const override;

private:

  GuiComp_Text text_;

  void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) override;

};}