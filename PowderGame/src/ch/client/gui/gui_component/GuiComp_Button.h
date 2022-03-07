#pragma once

#include <limits>
#include <string>
#include <functional>

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumSides.h"
#include "../../../utils/EnumGui3State.h"

#include "GuiComp.h"




namespace ch {

enum class EnumButtonKinds {
  NULL_BUTTON,
  COMMON,
};

enum class EnumButtonMove {
  NOTHING,
  CLOSE_THIS_GUI,
  DO_FUNCTION_POINTER,
};

class Gui;

class GuiComp_Button : public GuiComp {

public:

  GuiComp_Button(ch::EnumSides side, int xGap, int yGap, int width, int height, EnumButtonKinds buttonKind,
                 std::wstring text_, int btn_text_size, EnumButtonMove button_move_type);
  ~GuiComp_Button();

  EnumGui3State state_ = EnumGui3State::DEFAULT;
  std::function<void(Gui* gui)> onClicked;

  inline EnumButtonMove getMoveType() const {
    return move_type_;
  }

  void render(sf::RenderWindow& winddow) const override;

private:

  sf::Sprite sf_sprite_[3];
  sf::Text sf_text_;
  const int text_size_;
  const EnumButtonMove move_type_;

  void setTransformedAABB_(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) override;
};

}