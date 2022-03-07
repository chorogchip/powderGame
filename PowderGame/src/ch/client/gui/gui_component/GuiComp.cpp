#include "GuiComp.h"



namespace ch {


GuiComp::GuiComp(ch::EnumSides side, int xGap, int yGap, int width, int height) :
	FittablePosition(side, xGap, yGap, width, height) {

}

GuiComp::~GuiComp() { }



}