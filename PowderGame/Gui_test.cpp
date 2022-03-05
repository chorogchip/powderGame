#include "Gui_test.h"

Gui_test::Gui_test() : ch::Gui(ch::EnumSides::FULL, 0, 0, 0, 0) {
  
  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::BOTTOM_RIGHT, -50, -100, 48, 48,
                                           ch::EnumButtonKinds::COMMON, L"asdf", 20, ch::EnumButtonMove::CLOSE_THIS_GUI));
  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::TOP_LEFT, 50, 100, 16, 16, 4, 1));
  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::TOP_LEFT, 50, 150, 48, 16, 4, 1));
  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::TOP_LEFT, 50, 200, 48 * 16, 48, 4, 0));
  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::TOP_LEFT, 50, 250, 48 * 16, 48, 4, 1));
  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::TOP_LEFT, 50, 300, 48 * 16, 48, 4, 4));

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::TOP_LEFT, 700, 200, 500, 100));
}

Gui_test::~Gui_test() {}

