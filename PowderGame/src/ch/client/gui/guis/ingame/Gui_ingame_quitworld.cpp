#include "Gui_ingame_quitworld.h"

#include "../../../../scene/scenes/Scene_menu0_start.h"
#include "../../../../main/Game.h"

Gui_ingame_quitworld::Gui_ingame_quitworld() : Gui(ch::EnumSides::MIDDLE_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f) {
  setClosableByESC();

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::TOP_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f));

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::TOP_MIDDLE, 0.0f, 10.0f, 256.0f, 24.0f));
  
  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 280.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"게임 종료", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void {
    this->to_close_ = true;
    ch::Game::getInstance()->quitWorld();
    ch::Game::getInstance()->changeScene(new Scene_menu0_start());
  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 350.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"뒤로", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void {
    this->to_close_ = true;
    ch::Game::getInstance()->getWorld().continueWorld();
  };
}

Gui_ingame_quitworld::~Gui_ingame_quitworld() {
  ch::Game::getInstance()->getWorld().continueWorld();
}


