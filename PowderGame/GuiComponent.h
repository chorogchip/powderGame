#pragma once
#include <SFML/Graphics.hpp>
#include "EnumSides.h"
#include "sfAABB.h"
#include "EnumFonts.h"

class GuiComponent {
public:
	GuiComponent(EnumSides side, int xGap, int yGap, int width, int height);
	virtual ~GuiComponent();

	const EnumSides side_;
	const int xGap_;
	const int yGap_;
	const int width_;
	const int height_;
	sfAABB transformedPosNSize;

	void setTransformedPosNSize(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale);

private:
	virtual void setTransformedPosNSize_(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) = 0;

};

