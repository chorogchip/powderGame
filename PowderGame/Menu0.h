#pragma once
#include "Menu.h"

class Menu0 : public Menu {
public:
	Menu0();
	~Menu0();

	void handleEvent() override;
	void update() override;
	void render() override;
};

