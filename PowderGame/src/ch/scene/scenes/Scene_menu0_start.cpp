#include "Scene_menu0_start.h"
#include "../../main/Game.h"

/**
#define ch_sadsadasdasdwdjwajdwiadixcjwfjenljfnjsbjkfbsefbs
/**/

#ifdef ch_sadsadasdasdwdjwajdwiadixcjwfjenljfnjsbjkfbsefbs
#include "Gui_test.h"
#endif

Scene_menu0_start::Scene_menu0_start() {
  addGui(new Gui_scene_menu0_start());

#ifdef ch_sadsadasdasdwdjwajdwiadixcjwfjenljfnjsbjkfbsefbs
  guis_push_back(new Gui_test());
#endif

}

Scene_menu0_start::~Scene_menu0_start() {}

