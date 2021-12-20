#pragma once
#include <SFML/Graphics.hpp>
#include "World.h"

class WorldEventHandler {
public:
	WorldEventHandler();
	~WorldEventHandler();

	void handleEvents(World& world);
};

