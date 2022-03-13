
#include "GuiComp_TextHolder.h"

#include "../../../main/Game.h"

namespace ch {

GuiComp_TextHolder::GuiComp_TextHolder(ch::EnumSides side, float xGap, float yGap, float width, float height, ch::EnumSides text_side, std::wstring text_text, float text_size)
  : GuiComp(side, xGap, yGap, width, height), text_(text_side, 0, 0, 0, 0, text_text, text_size) {
  /*
  auto loc_b = text_.getTextLocalBounds();
  auto this_aabb = this->getTransformedAABB();
  text_.setSize(loc_b.width, loc_b.height, this_aabb.pos.x, this_aabb.pos.y, this_aabb.size.x, this_aabb.size.y, Game::getInstance()->getRenderstate().ui_scale);*/
}

GuiComp_TextHolder::~GuiComp_TextHolder() { }

void GuiComp_TextHolder::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) {
  auto this_aabb = getTransformedAABB();
  text_.setTransformedAABB(this_aabb.pos.x, this_aabb.pos.y, this_aabb.size.x, this_aabb.size.y, GUI_scale);
}

void GuiComp_TextHolder::render(sf::RenderWindow& window) const {
  text_.render(window);
}

}