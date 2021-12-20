#pragma once
#include <SFML/Graphics.hpp>
#include "Menu.h"

class MenuEventHandler {
public:
	MenuEventHandler();
	~MenuEventHandler();

	void handleEvents(Menu& menu);
};

