#include "Gui_gameoverlay_toolbar.h"

#include "../../../../main/Game.h"

  // interval bewteen buttons
  constexpr float INTV = 4.0f;
  //button size
  constexpr float SIZ = 48.0f;
  
  constexpr float INTPSIZ = INTV + SIZ;

Gui_gameoverlay_toolbar::Gui_gameoverlay_toolbar() : ch::Gui(ch::EnumSides::BOTTOM_MIDDLE, 0.0f, -10.0f, 1088.0f, 112.0f) {
  

  gui_backgrounds_.push_back({ ch::EnumSides::FULL, 0, 0, 0, 0 });

  gui_sprites_.push_back({ ch::EnumSides::BOTTOM_LEFT, INTV + 0.0f * SIZ, -INTV, SIZ, SIZ });
  gui_sprites_.back().setTexture(ch::Game::getInstance()->getTextureLoader().getTexture_GameOverlay_Btn(19));
  gui_sprites_.push_back({ ch::EnumSides::BOTTOM_LEFT, INTV + 2.5f * SIZ, -INTV, SIZ, SIZ });
  gui_sprites_.back().setTexture(ch::Game::getInstance()->getTextureLoader().getTexture_GameOverlay_Btn(20));
  gui_sprites_.push_back({ ch::EnumSides::BOTTOM_LEFT, INTV + 3.5f * SIZ, -INTV, SIZ, SIZ });
  gui_sprites_.back().setTexture(ch::Game::getInstance()->getTextureLoader().getTexture_GameOverlay_Btn(21));
  gui_sprites_.push_back({ ch::EnumSides::BOTTOM_LEFT, INTV + 6.0f * SIZ, -INTV, SIZ, SIZ });
  gui_sprites_.back().setTexture(ch::Game::getInstance()->getTextureLoader().getTexture_GameOverlay_Btn(22));

  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::BOTTOM_LEFT, INTV + SIZ * 0.5f, -INTV + (64.0f - SIZ) / 2.0f, 128.0f, 64.0f, 127, 0));
  gui_bars_.push_back(ch::GuiComp_Bar(ch::EnumSides::BOTTOM_LEFT, INTV + SIZ * 4.0f, -INTV + (64.0f - SIZ) / 2.0f, 128.0f, 64.0f, 127, 0));
  
  addBtn(static_cast<int>(EnumOVST_Tool::PENCIL),       0.0f, [&]() -> void { selected_tool_ = EnumOVST_Tool::PENCIL; });
  addBtn(static_cast<int>(EnumOVST_Tool::ERASER),       1.0f, [&]() -> void { selected_tool_ = EnumOVST_Tool::ERASER; });
  addBtn(static_cast<int>(EnumOVST_Tool::SPRAY),        2.0f, [&]() -> void { selected_tool_ = EnumOVST_Tool::SPRAY; });
  addBtn(static_cast<int>(EnumOVST_Tool::PAINTBUCKET),  3.0f, [&]() -> void { selected_tool_ = EnumOVST_Tool::PAINTBUCKET; });
  addBtn(static_cast<int>(EnumOVST_Tool::PIPET),        4.0f, [&]() -> void { selected_tool_ = EnumOVST_Tool::PIPET; });

  addBtn(static_cast<int>(EnumOVST_OtherState::PAUSE), 5.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::Z),  6.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::X),  7.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::C),  8.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::V),  9.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::B), 10.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::R), 11.0f, [&]() -> void { });
  addBtn(static_cast<int>(EnumOVST_OtherState::GROUND_ON),   12.0f, [&]() -> void { has_ground_ = !has_ground_; });
  addBtn(static_cast<int>(EnumOVST_OtherState::GRAVITY_ON),  13.0f, [&]() -> void { has_gravity_ = !has_gravity_; });
  
}

Gui_gameoverlay_toolbar::~Gui_gameoverlay_toolbar() { }

inline void Gui_gameoverlay_toolbar::addBtn(int tex_num, float pos_num, std::function<void()>&& on_cicked) {
  gui_buttons_.push_back(ch::GuiComp_Button(ch::EnumSides::BOTTOM_LEFT, SIZ * 7.5f + INTPSIZ * pos_num, -INTV, SIZ, SIZ, ch::EnumButtonKinds::COMMON, L"", 0.0f, ch::EnumButtonMove::DO_FUNCTION_POINTER));
  gui_buttons_.back().setTexture(ch::Game::getInstance()->getTextureLoader().getTexture_GameOverlay_Btn(tex_num));
  gui_buttons_.back().onClicked = on_cicked;
}