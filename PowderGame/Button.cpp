#include "Button.h"



Button::Button(EnumSides side_, int xGap_, int yGap_, int width_, int height_) :
	side(side_), xGap(xGap_), yGap(yGap_), width(width_), height(height_),
	toRenderText(false), textSide(EnumSides::NULL_SIDE){
	
	

}


Button::~Button() {}
