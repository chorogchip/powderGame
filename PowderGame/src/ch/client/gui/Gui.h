#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "../../utils/EnumActionResult.h"
#include "../../utils/AABB.h"
#include "../../utils/EnumSides.h"

#include "FittablePosition.h"
#include "gui_component/GuiComp.h"
#include "gui_component/GuiComp_Button.h"
#include "gui_component/GuiComp_Bar.h"
#include "gui_component/GuiComp_Background.h"
#include "gui_component/GuiComp_MoveBar.h"
#include "gui_component/GuiComp_Textbox.h"


namespace ch {


class Gui : public FittablePosition {

public:

  Gui(ch::EnumSides side, int xPos, int yPos, int width, int height);
  virtual ~Gui();

  
  virtual ch::EnumActionResult onEvent_MouseEntered(ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_MouseLeft(ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_TextEntered(sf::Event::TextEvent& evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_KeyPressed(sf::Event::KeyEvent& evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_KeyReleased(sf::Event::KeyEvent& evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_MouseWheelScrolled(sf::Event::MouseWheelScrollEvent& evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_MouseButtonPressed(sf::Event::MouseButtonEvent& evnt, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_MouseButtonReleased(sf::Event::MouseButtonEvent& evn, ch::EnumActionResult prev);
  virtual ch::EnumActionResult onEvent_MouseMoved(sf::Event::MouseMoveEvent& evnt, ch::EnumActionResult prev);
  virtual void update();
  virtual void render() const;

  inline bool isToClose() const {
    return to_close_;
  }
protected:

  bool to_close_ = false;

  std::vector<GuiComp_Button> gui_buttons_;
  std::vector<GuiComp_Bar> gui_bars_;
  std::vector<GuiComp_Background> gui_backgrounds_;
  std::vector<GuiComp_MoveBar> gui_movebars_;
  std::vector<GuiComp_Textbox> gui_textboxes_;

private:

  void setTransformedAABB_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) override;
  inline void setAllComponentDefault();
  inline ch::EnumActionResult updateMouse(int mouseX, int mouseY, ch::EnumActionResult prev);

};

}