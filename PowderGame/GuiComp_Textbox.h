#pragma once

#include <utility>
#include <string>

#include <SFML/Graphics.hpp>

#include "EnumGui3State.h"

#include "GuiComponent.h"


namespace ch {


enum class EnumTextboxKinds {
  UNSIGNED_INT,
  SIGNED_INT,
  TEXT_LINE,
  TEXT_BOX,


};
inline bool isNum(EnumTextboxKinds kind) {
  return kind == EnumTextboxKinds::UNSIGNED_INT || kind == EnumTextboxKinds::SIGNED_INT;
}
inline bool isText(EnumTextboxKinds kind) {
  return kind == EnumTextboxKinds::TEXT_LINE || kind == EnumTextboxKinds::TEXT_BOX;
}


class GuiComp_Textbox : public GuiComponent {

public:

  GuiComp_Textbox(ch::EnumSides side, int xGap, int yGap, int width, int height, int textbox_text_size, EnumTextboxKinds textboxKind);
  ~GuiComp_Textbox();

  const int text_size_;

  EnumGui3State state_ = EnumGui3State::DEFAULT;

  inline EnumTextboxKinds getKind() const {
    return kind_;
  }

  void inputUnicode(int unicode);
  void inputKeyboard(sf::Keyboard::Key keyboard);
  void cookNum();

  void setWStr(std::wstring wstr);
  void setLimits(long long var_default, long long limit_min, long long limit_max);

  void render(sf::RenderWindow& window) const override;

private:

  sf::Sprite sf_sprite_[3];
  sf::Text sf_text_;

  const EnumTextboxKinds kind_;
  std::wstring wstr_;
  int wstr_cursor_ = 0;

  long long var_default_ = 0LL;
  long long limit_min_ = 0LL;
  long long limit_max_ = static_cast<long long>(std::numeric_limits<int>::max());
  void setTransformedAABB_(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) override;
};

}