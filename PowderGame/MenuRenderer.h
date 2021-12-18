#pragma once
#include "Menu.h"

class MenuRenderer {
public:
	MenuRenderer();
	~MenuRenderer();

	void render(Menu& menu);
};

