#include "GuiComponent.h"



GuiComponent::GuiComponent(EnumSides side, int xGap, int yGap, int width, int height):
	side_(side), xGap_(xGap), yGap_(yGap), width_(width), height_(height) {

}

GuiComponent::~GuiComponent() {}

void GuiComponent::setTransformedPosNSize(int GUI_xPos, int GUI_yPos, int GUI_width_scaled, int GUI_height_scaled, float GUI_scale) {
	float xG = GUI_scale * xGap_;
	float yG = GUI_scale * yGap_;
	float wid = GUI_scale * width_;
	float hei = GUI_scale * height_;

	float wdx = GUI_width_scaled;
	float wdy = GUI_height_scaled;

	switch (side_) {

	case EnumSides::TOP_LEFT:		transformedPosNSize.pos = sf::Vector2f(                    xG, yG);							break;
	case EnumSides::TOP_MIDDLE:		transformedPosNSize.pos = sf::Vector2f(((wdx - wid) / 2) + xG, yG);							break;
	case EnumSides::TOP_RIGHT:		transformedPosNSize.pos = sf::Vector2f(wdx - wid         + xG, yG);							break;
	case EnumSides::MIDDLE_LEFT:	transformedPosNSize.pos = sf::Vector2f(                    xG, ((wdy - hei) / 2) + yG);		break;
	case EnumSides::MIDDLE_MIDDLE:	transformedPosNSize.pos = sf::Vector2f(((wdx - wid) / 2) + xG, ((wdy - hei) / 2) + yG);		break;
	case EnumSides::MIDDLE_RIGHT:	transformedPosNSize.pos = sf::Vector2f(wdx - wid         + xG, ((wdy - hei) / 2) + yG);		break;
	case EnumSides::BOTTOM_LEFT:	transformedPosNSize.pos = sf::Vector2f(                    xG, wdy - hei + yG);				break;
	case EnumSides::BOTTOM_MIDDLE:	transformedPosNSize.pos = sf::Vector2f(((wdx - wid) / 2) + xG, wdy - hei + yG);				break;
	case EnumSides::BOTTOM_RIGHT:	transformedPosNSize.pos = sf::Vector2f(wdx - wid         + xG, wdy - hei + yG);				break;

	default: return;
	}
	transformedPosNSize.pos = transformedPosNSize.pos + sf::Vector2f(GUI_xPos, GUI_yPos);
	transformedPosNSize.size = sf::Vector2f(wid, hei);
	setTransformedPosNSize_(GUI_xPos, GUI_yPos, GUI_width_scaled, GUI_height_scaled, GUI_scale);

}