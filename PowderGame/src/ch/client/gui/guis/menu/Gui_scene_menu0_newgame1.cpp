
#include "Gui_scene_menu0_newgame1.h"

#include "../../../../main/Game.h"
#include "Gui_scene_menu0_start.h"
#include "../etc/Gui_Etc_Error_Basic.h"
#include "../../../../scene/scenes/Scene_PowderGame.h"
#include "../../../../world/World.h"

Gui_scene_menu0_newgame1::Gui_scene_menu0_newgame1() : ch::Gui(ch::EnumSides::MIDDLE_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f) {

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::TOP_MIDDLE, 0.0f, 0.0f, 288.0f, 427.0f));

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::TOP_MIDDLE, 0.0f, 10.0f, 256.0f, 24.0f));

  gui_textholders_.push_back(ch::GuiComp_TextHolder(ch::EnumSides::TOP_MIDDLE, 0.0f, 70.0f, 256.0f, 20.0f, ch::EnumSides::BOTTOM_LEFT, L"map X", 20.0f));
  gui_textboxes_.push_back(ch::GuiComp_Textbox(ch::EnumSides::TOP_MIDDLE, 0.0f, 100.0f, 256.0f, 32.0f, 20.0f, ch::EnumTextboxKinds::UNSIGNED_INT));
  gui_textboxes_.back().setLimits(500LL, 0LL, 50000LL);

  gui_textholders_.push_back(ch::GuiComp_TextHolder(ch::EnumSides::TOP_MIDDLE, 0.0f, 140.0f, 256.0f, 20.0f, ch::EnumSides::BOTTOM_LEFT, L"map Y", 20.0f));
  gui_textboxes_.push_back(ch::GuiComp_Textbox(ch::EnumSides::TOP_MIDDLE, 0.0f, 170.0f, 256.0f, 32.0f, 20.0f, ch::EnumTextboxKinds::UNSIGNED_INT));
  gui_textboxes_.back().setLimits(500LL, 0LL, 50000LL);

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 280.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"게임 시작", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void {
    ch::World* world = new ch::World(gui_textboxes_[0].getData_Int(), gui_textboxes_[1].getData_Int());
    auto res = world->init();
    if (res == ch::EnumActionResult::SUCCEED) {
      ch::Game::getInstance()->changeWorld(world);
      ch::Game::getInstance()->changeScene(new Scene_PowderGame());
    } else {
      delete world;
      ch::Game::getInstance()->addGuiToScene(new Gui_Etc_Error_Basic(L"월드를 생성하는 데 실패했습니다."));
    }
  };

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::TOP_MIDDLE, 0.0f, 350.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"뒤로", 35.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().onClicked = [&]() -> void { ch::Game::getInstance()->addGuiToScene(new Gui_scene_menu0_start()); this->to_close_ = true;  };
}

Gui_scene_menu0_newgame1::~Gui_scene_menu0_newgame1() {}

