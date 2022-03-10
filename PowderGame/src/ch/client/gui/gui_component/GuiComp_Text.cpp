#include "GuiComp_Text.h"

#include "../../../main/Game.h"



namespace ch {

GuiComp_Text::GuiComp_Text(ch::EnumSides side, float xGap, float yGap, float width, float height, std::wstring text, float text_size)
  : GuiComp(side, xGap, yGap, width, height), text_size_(text_size) {

  text_.setFont(Game::getInstance()->getFont(ch::EnumGameFonts::BASIC));
  text_.setString(text);
  text_.setFillColor(sf::Color::Black);
  text_.setCharacterSize(static_cast<unsigned int>(text_size));

}

GuiComp_Text::~GuiComp_Text() { }

void GuiComp_Text::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) {
  if (!resized_text_size_) {
    resized_text_size_ = true;
    text_.setCharacterSize(static_cast<unsigned int>(text_size_ * GUI_scale));
    sf::FloatRect text_rect = text_.getLocalBounds();
    setSize(text_rect.width, text_rect.height, GUI_xPos, GUI_yPos, GUI_width_scaled, GUI_height_scaled, GUI_scale);
  } else {
    resized_text_size_ = false;
    text_.setPosition(getTransformedAABB().pos);
  }

}

void GuiComp_Text::render(sf::RenderWindow& window) const {
  window.draw(text_);
}

}