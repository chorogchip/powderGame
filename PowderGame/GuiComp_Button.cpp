#include "GuiComp_Button.h"
#include "Game.h"


GuiComp_Button::GuiComp_Button(EnumSides side, int xGap, int yGap, int width, int height, ButtonKinds buttonKind, std::wstring text, int btn_size):
	GuiComponent(side, xGap, yGap, width, height), btn_size_(btn_size){

	btn_text_.setFont(Game::getInstance()->getFont(GameFonts::BASIC));
	btn_text_.setString(text);
	btn_text_.setFillColor(sf::Color::White);
	btn_text_.setCharacterSize(btn_size);
	switch (buttonKind) {



	default: break;

	}

}

GuiComp_Button::~GuiComp_Button() {
	
}

void GuiComp_Button::setTransformedPosNSize_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) {
	btn_sprite_.setPosition(transformedPosNSize.pos);
	btn_sprite_.setScale(sf::Vector2f(GUI_scale, GUI_scale));

	btn_text_.setCharacterSize(btn_size_ * GUI_scale);
	sf::FloatRect textRect = btn_text_.getLocalBounds();
	btn_text_.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	btn_text_.setPosition(transformedPosNSize.pos + sf::Vector2f(transformedPosNSize.size.x / 2.0f, transformedPosNSize.size.y / 2.0f));
}