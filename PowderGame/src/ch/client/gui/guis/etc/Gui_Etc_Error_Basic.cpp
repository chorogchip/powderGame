#include "Gui_Etc_Error_Basic.h"

#include "../../../../main/Game.h"

Gui_Etc_Error_Basic::Gui_Etc_Error_Basic(std::wstring wstr) : ch::Gui(ch::EnumSides::MIDDLE_MIDDLE, 0.0f, 0.0f, 512.0f, 512.0f) {

  gui_backgrounds_.push_back(ch::GuiComp_Background(ch::EnumSides::TOP_MIDDLE, 0.0f, 0.0f, 512.0f, 512.0f));

  gui_movebars_.push_back(ch::GuiComp_MoveBar(ch::EnumSides::TOP_MIDDLE, 0.0f, 10.0f, 500.0f, 24.0f));

  gui_textholders_.push_back(ch::GuiComp_TextHolder(ch::EnumSides::TOP_MIDDLE, 0.0f, 52.0f, 512.0f, 460.0f, ch::EnumSides::TOP_LEFT, wstr, 15.0f));

  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::BOTTOM_RIGHT, 0.0f, 0.0f, 256.0f, 64.0f, ch::EnumButtonKinds::COMMON, L"´Ý±â", 35.0f, ch::EnumButtonMove::CLOSE_THIS_GUI));


}

Gui_Etc_Error_Basic::~Gui_Etc_Error_Basic() {}

