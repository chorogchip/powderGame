#pragma once
#include "Scene.h"

class SceneRenderer {
public:
	SceneRenderer();
	~SceneRenderer();

	void render(Scene& scene);
};

