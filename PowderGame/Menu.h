#pragma once
#include <vector>
#include "Button.h"

class Menu {
public:
	Menu();
	virtual ~Menu();

	virtual void handleEvent() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	std::vector<Button> buttons;
	
	void updatePosNScale();
	
};

