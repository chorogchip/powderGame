#pragma once

#include "Scene.h"

namespace ch {


class SceneRenderer {
public:
	SceneRenderer();
	~SceneRenderer();

	void render(Scene& scene);
};

}