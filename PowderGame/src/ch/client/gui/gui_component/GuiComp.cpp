#include "GuiComp.h"



namespace ch {


GuiComp::GuiComp(ch::EnumSides side, float xGap, float yGap, float width, float height)
	: FittablePosition(side, xGap, yGap, width, height) {

}

GuiComp::~GuiComp() { }


}