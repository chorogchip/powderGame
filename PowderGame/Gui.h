#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "EnumActionResult.h"
#include "GuiComponent.h"
#include "GuiComp_Button.h"

class Gui {
public:

	Gui();
	virtual ~Gui();

	EnumActionResult handleEvent(sf::Event& evnt);
	void tick();
	void render();

	std::vector<GuiComp_Button> gui_buttons;


	int xPos_;
	int yPos_;
	const int width_;
	const int height_;

private:

	virtual EnumActionResult handleEvent_(sf::Event& evnt) = 0;
	virtual void tick_() = 0;
	virtual void render_() = 0;
};

