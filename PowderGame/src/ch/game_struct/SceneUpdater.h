#pragma once

#include "../scene/Scene.h"


namespace ch {

class SceneUpdater {

public:

  SceneUpdater();
  ~SceneUpdater();
  SceneUpdater (const SceneUpdater&) = delete;
  SceneUpdater& operator=(const SceneUpdater&) = delete;

  void update(Scene& scene);

};

}