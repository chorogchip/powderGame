#include "GuiComponent.h"



namespace ch {


GuiComponent::GuiComponent(ch::EnumSides side, int xGap, int yGap, int width, int height) :
	FittablePosition(side, xGap, yGap, width, height) {

}

GuiComponent::~GuiComponent() { }



}