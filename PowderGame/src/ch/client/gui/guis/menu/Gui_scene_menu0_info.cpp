#include "Gui_scene_menu0_info.h"

#include "../../../../main/Game.h"
#include "Gui_scene_menu0_start.h"

Gui_scene_menu0_info::Gui_scene_menu0_info() : ch::Gui(ch::EnumSides::MIDDLE_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f) {

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::TOP_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f));

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::TOP_MIDDLE, 0.0f, 10.0f, 256.0f, 24.0f));

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 350.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"µÚ·Î", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_start()); this->to_close_ = true;  };



}

Gui_scene_menu0_info::~Gui_scene_menu0_info() {}

