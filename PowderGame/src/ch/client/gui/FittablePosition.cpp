#include "FittablePosition.h"


namespace ch {

FittablePosition::FittablePosition(ch::EnumSides side, float xGap, float yGap, float width, float height)
  : side_(side), xGap_(xGap), yGap_(yGap), width_(width), height_(height) { }

FittablePosition::~FittablePosition() { }



void FittablePosition::setTransformedAABB(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {

  const float xG = scale * xGap_;
  const float yG = scale * yGap_;
  const float wid = scale * width_;
  const float hei = scale * height_;

  const float wdx = upper_width_scaled;
  const float wdy = upper_height_scaled;

  switch (side_) {
  case ch::EnumSides::FULL:          transformedAABB_.pos = sf::Vector2f(xG, yG); break;
  case ch::EnumSides::TOP_LEFT:      transformedAABB_.pos = sf::Vector2f(xG, yG); break;
  case ch::EnumSides::TOP_MIDDLE:    transformedAABB_.pos = sf::Vector2f(((wdx - wid) / 2) + xG, yG); break;
  case ch::EnumSides::TOP_RIGHT:     transformedAABB_.pos = sf::Vector2f(wdx - wid + xG, yG); break;
  case ch::EnumSides::MIDDLE_LEFT:   transformedAABB_.pos = sf::Vector2f(xG, ((wdy - hei) / 2) + yG); break;
  case ch::EnumSides::MIDDLE_MIDDLE: transformedAABB_.pos = sf::Vector2f(((wdx - wid) / 2) + xG, ((wdy - hei) / 2) + yG); break;
  case ch::EnumSides::MIDDLE_RIGHT:  transformedAABB_.pos = sf::Vector2f(wdx - wid + xG, ((wdy - hei) / 2) + yG); break;
  case ch::EnumSides::BOTTOM_LEFT:   transformedAABB_.pos = sf::Vector2f(xG, wdy - hei + yG); break;
  case ch::EnumSides::BOTTOM_MIDDLE: transformedAABB_.pos = sf::Vector2f(((wdx - wid) / 2) + xG, wdy - hei + yG);  break;
  case ch::EnumSides::BOTTOM_RIGHT:  transformedAABB_.pos = sf::Vector2f(wdx - wid + xG, wdy - hei + yG); break;

  default: return;
  }
  transformedAABB_.pos += sf::Vector2f(upper_xPos, upper_yPos);
  transformedAABB_.size = sf::Vector2f(wid, hei);
  if (side_ == ch::EnumSides::FULL) {
    transformedAABB_.size = sf::Vector2f(wdx, wdy);
  }
  setTransformedAABB_(upper_xPos, upper_yPos, upper_width_scaled,
                             upper_height_scaled, scale);
}

void FittablePosition::setTransformedAABB_(float GUI_xPos, float GUI_yPos, float GUI_width_scaled, float GUI_height_scaled, float GUI_scale) { }



}