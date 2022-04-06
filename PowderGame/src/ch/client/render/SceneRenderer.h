#pragma once

#include "../../scene/Scene.h"

namespace ch {


class SceneRenderer {
public:
	SceneRenderer();
	~SceneRenderer();
	SceneRenderer (const SceneRenderer&) = delete;
	SceneRenderer& operator=(const SceneRenderer&) = delete;

	void render(Scene& scene);
};

}