#pragma once
#include <SFML/Graphics.hpp>
#include "GuiComponent.h"

enum class ButtonKinds {
	NULL_BUTTON,
	MAIN_MENU,
};


class GuiComp_Button : public GuiComponent {
public:
	GuiComp_Button(EnumSides side_, int xGap_, int yGap_, int width_, int height_, ButtonKinds buttonKind, std::wstring text_, int btn_size_);
	~GuiComp_Button();

	sf::Sprite btn_sprite_;
	sf::Text btn_text_;
	const int btn_size_;

private:

	void setTransformedPosNSize_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) override;
};

