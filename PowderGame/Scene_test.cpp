#include "Scene_test.h"
#include "Game.h"

Scene_test::Scene_test() {
  ch::Gui* test = new Gui_test();
  addGui(test);
}

Scene_test::~Scene_test() {}


