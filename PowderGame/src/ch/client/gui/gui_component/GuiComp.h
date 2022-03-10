#pragma once

#include <SFML/Graphics.hpp>

#include "../../../utils/EnumSides.h"
#include "../../EnumFonts.h"

#include "../FittablePosition.h"


namespace ch {
class GuiComp : public FittablePosition {

public:
  GuiComp(ch::EnumSides side, float xGap, float yGap, float width, float height);
  virtual ~GuiComp();

  virtual void render(sf::RenderWindow& winddow) const = 0;

private:

};}
