#include "GuiComp_Button.h"

#include "../../../main/Game.h"



namespace ch {


GuiComp_Button::GuiComp_Button(ch::EnumSides side, float xGap, float yGap, float width, float height,
                               EnumButtonKinds buttonKind, std::wstring text, float text_size,
                               EnumButtonMove button_move_type)
  : GuiComp(side, xGap, yGap, width, height), text_size_(text_size), move_type_(button_move_type) {

  sf_text_.setFont(Game::getInstance()->getFont(ch::EnumGameFonts::BASIC));
  sf_text_.setString(text);
  sf_text_.setFillColor(sf::Color::Black);
  sf_text_.setCharacterSize(static_cast<unsigned int>(text_size));

  switch (buttonKind) {

  case EnumButtonKinds::COMMON:
  default:
    Game::getInstance()->getTextureLoader().setTexture_Button(sf_sprite_[0], sf_sprite_[1], sf_sprite_[2], static_cast<int>(width), static_cast<int>(height));
  }
}

GuiComp_Button::~GuiComp_Button() { }

void GuiComp_Button::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) {
  sf_sprite_[0].setPosition(getTransformedAABB().pos);
  sf_sprite_[1].setPosition(getTransformedAABB().pos);
  sf_sprite_[2].setPosition(getTransformedAABB().pos);
  sf_sprite_[0].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_[1].setScale(sf::Vector2f(GUI_scale, GUI_scale));
  sf_sprite_[2].setScale(sf::Vector2f(GUI_scale, GUI_scale));

  sf_text_.setCharacterSize(static_cast<unsigned int>(text_size_ * GUI_scale));
  sf::FloatRect textRect = sf_text_.getLocalBounds();
  sf_text_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  sf_text_.setPosition(getTransformedAABB().pos + sf::Vector2f(getTransformedAABB().size.x / 2.0f, getTransformedAABB().size.y / 2.0f));

}

void GuiComp_Button::render(sf::RenderWindow& winddow) const {
  winddow.draw(sf_sprite_[static_cast<int>(state_)]);
  winddow.draw(sf_text_);
}

}