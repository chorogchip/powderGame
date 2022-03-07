#include "Gui_scene_menu0_start.h"

#include "../../../main/Game.h"
#include "Gui_scene_menu0_option.h"
#include "Gui_scene_menu0_info.h"

Gui_scene_menu0_start::Gui_scene_menu0_start() : ch::Gui(ch::EnumSides::MIDDLE_MIDDLE, 0, 0, 288, 416) {
  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::MIDDLE_MIDDLE, 0, -115, 256, 64, ch::EnumButtonKinds::COMMON, L"새로운 게임", 35, ch::EnumButtonMove::NOTHING));

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::MIDDLE_MIDDLE, 0,  -45, 256, 64, ch::EnumButtonKinds::COMMON, L"불러오기", 35, ch::EnumButtonMove::NOTHING));

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::MIDDLE_MIDDLE, 0,   25, 256, 64, ch::EnumButtonKinds::COMMON, L"설정", 35, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&](ch::Gui* gui) -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_option()); this->to_close_ = true;  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::MIDDLE_MIDDLE, 0,   95, 256, 64, ch::EnumButtonKinds::COMMON, L"정보", 35, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&](ch::Gui* gui) -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_info()); this->to_close_ = true;  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::MIDDLE_MIDDLE, 0,  165, 256, 64, ch::EnumButtonKinds::COMMON, L"나가기", 35, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [](ch::Gui* gui) -> void { ch::Game::getInstance()->quit(); };

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::MIDDLE_MIDDLE, 0, -190, 256, 24));

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::MIDDLE_MIDDLE, 0, 0, 288, 416));

}

Gui_scene_menu0_start::~Gui_scene_menu0_start() {}

