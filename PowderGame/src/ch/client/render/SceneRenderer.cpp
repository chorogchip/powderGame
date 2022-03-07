#include "SceneRenderer.h"
#include "../../main/Game.h"


namespace ch {

SceneRenderer::SceneRenderer() { }

SceneRenderer::~SceneRenderer() { }

void SceneRenderer::render(Scene& scene) {
  scene.render();
  for (auto& o : scene.guis_) {
    o->render();
  }

}

}