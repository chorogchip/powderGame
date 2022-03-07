#include "GuiComp_Text.h"

#include "Game.h"


namespace ch {

GuiComp_Text::GuiComp_Text(ch::EnumSides side, int xGap, int yGap, int width, int height, std::wstring text, int text_size)
  : GuiComponent(side, xGap, yGap, width, height), text_size_(text_size) {

  text_.setFont(Game::getInstance()->getFont(ch::EnumGameFonts::BASIC));
  text_.setString(text);
  text_.setFillColor(sf::Color::Black);
  text_.setCharacterSize(text_size);

}

GuiComp_Text::~GuiComp_Text() { }

void GuiComp_Text::setTransformedAABB_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) {

  text_.setCharacterSize(static_cast<unsigned int>(text_size_ * GUI_scale));
  sf::FloatRect textRect = text_.getLocalBounds();
  text_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
  text_.setPosition(getTransformedAABB().pos + sf::Vector2f(getTransformedAABB().size.x / 2.0f, getTransformedAABB().size.y / 2.0f));

}

void GuiComp_Text::render(sf::RenderWindow& window) const {
  window.draw(text_);
}

}