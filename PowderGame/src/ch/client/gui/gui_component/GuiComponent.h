#pragma once

#include <SFML/Graphics.hpp>

#include "EnumSides.h"
#include "EnumFonts.h"

#include "FittablePosition.h"


namespace ch {

class GuiComponent : public FittablePosition {
public:
  GuiComponent(ch::EnumSides side, int xGap, int yGap, int width, int height);
  virtual ~GuiComponent();

  virtual void render(sf::RenderWindow& winddow) const = 0;

private:
};

}

