#include "SceneUpdater.h"


namespace ch {


SceneUpdater::SceneUpdater() {

}

SceneUpdater::~SceneUpdater() {

}

void SceneUpdater::update(Scene& scene) {

  scene.update();

  for (auto& o : scene.guis_) {
    o->update();
  }

}

}