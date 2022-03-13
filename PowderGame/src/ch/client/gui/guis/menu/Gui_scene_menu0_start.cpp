#include "Gui_scene_menu0_start.h"

#include "../../../../main/Game.h"
#include "Gui_scene_menu0_option.h"
#include "Gui_scene_menu0_info.h"
#include "Gui_scene_menu0_newgame1.h"

Gui_scene_menu0_start::Gui_scene_menu0_start() : ch::Gui(ch::EnumSides::MIDDLE_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f) {

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::FULL, 0.0f, 0.0f, 0.0f, 0.0f));

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::TOP_MIDDLE, 0.0f, 10.0f, 256.0f, 24.0f));

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 70.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"새로운 게임", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_newgame1()); this->to_close_ = true;  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 140.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"불러오기", 35.0f, ch::EnumButtonMove::NOTHING));

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 210.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"설정", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_option()); this->to_close_ = true;  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 280.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"정보", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_info()); this->to_close_ = true;  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 350.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"나가기", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = []() -> void { ch::Game::getInstance()->quit(); };


}

Gui_scene_menu0_start::~Gui_scene_menu0_start() {}

