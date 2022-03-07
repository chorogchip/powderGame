#include "Gui_scene_menu0_option.h"

#include "Game.h"
#include "Gui_scene_menu0_start.h"

Gui_scene_menu0_option::Gui_scene_menu0_option() : ch::Gui(ch::EnumSides::MIDDLE_MIDDLE, 0, 0, 288, 416) {
  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::MIDDLE_MIDDLE, 0,  165, 256, 64, ch::EnumButtonKinds::COMMON, L"µÚ·Î", 35, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&](ch::Gui* gui) -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_start()); this->to_close_ = true;  };

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::MIDDLE_MIDDLE, 0, -190, 256, 24));

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::MIDDLE_MIDDLE, 0, 0, 288, 416));

  gui_textboxes_.push_back(ch::GuiComp_Textbox(ch::EnumSides::MIDDLE_MIDDLE, 0, 0, 256, 64, 30, ch::EnumTextboxKinds::UNSIGNED_INT));
  gui_textboxes_.back().setLimits(0LL, 0LL, 100LL);

}

Gui_scene_menu0_option::~Gui_scene_menu0_option() {}

