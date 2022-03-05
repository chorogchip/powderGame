#pragma once

#include "Scene.h"


namespace ch {

class SceneUpdater {

public:

  SceneUpdater();
  ~SceneUpdater();

  void update(Scene& scene);

};

}