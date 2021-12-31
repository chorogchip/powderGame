#pragma once
#include <SFML/Graphics.hpp>
#include "Scene.h"

class SceneEventHandler {
public:
	SceneEventHandler();
	~SceneEventHandler();

	void handleEvents(Scene& scene);
};

