#pragma once

#include <functional>

#include "../../Gui.h"

enum class EnumOVST_Tool : int {
  PENCIL      = 14,
  ERASER      = 15,
  SPRAY       = 16,
  PAINTBUCKET = 17,
  PIPET       = 18,
};
enum class EnumOVST_OtherState : int {
  PAUSE = 8,
  RUN = 9,
  Z = 1,
  X = 2,
  C = 3,
  V = 4,
  B = 5,
  R = 0,
  GROUND_ON = 10,
  GROUND_OFF = 11,
  GRAVITY_ON = 12,
  GRAVITY_OFF = 13,
};


class Gui_gameoverlay_toolbar : public ch::Gui {

public:
  Gui_gameoverlay_toolbar();
  ~Gui_gameoverlay_toolbar();

private:

  EnumOVST_Tool selected_tool_ = EnumOVST_Tool::PENCIL;
  bool has_ground_ = true;
  bool has_gravity_ = true;
  inline void addBtn(int tex_num, float pos_num, std::function<void()>&& on_cicked);
};

