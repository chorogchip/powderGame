#pragma once

#include "EnumSides.h"
#include "AABB.h"


namespace ch {

class FittablePosition {

public:
  FittablePosition(ch::EnumSides side, int xGap, int yGap, int width, int height);
  ~FittablePosition();

  void setTransformedAABB(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale);

  inline void setTransformedAABB(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {
    this->setTransformedAABB(static_cast<int>(upper_xPos), static_cast<int>(upper_yPos), static_cast<int>(upper_width_scaled), static_cast<int>(upper_height_scaled), scale);
  }
  inline void setTransformedAABB(sfAABB aabb, float scale) {
    this->setTransformedAABB(aabb.pos.x, aabb.pos.y, aabb.size.x, aabb.size.y, scale);
  }

  inline int get_xGap() const {
    return xGap_;
  }
  inline int get_yGap() const {
    return yGap_;
  }
  inline int get_width() const {
    return width_;
  }
  inline int get_height() const {
    return height_;
  }
  inline ch::sfAABB getTransformedAABB() const {
    return transformedAABB_;
  }

  inline void setPosision(int x, int y, int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) {
    xGap_ = x;
    yGap_ = y;
    setTransformedAABB(upper_xPos, upper_yPos, upper_width_scaled, upper_height_scaled, scale);
  }
  inline void setSize(int x, int y, int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale) {
    width_ = x;
    height_ = y;
    setTransformedAABB(upper_xPos, upper_yPos, upper_width_scaled, upper_height_scaled, scale);
  }

private:

  ch::EnumSides side_;
  int xGap_;
  int yGap_;
  int width_;
  int height_;
  ch::sfAABB transformedAABB_;
  virtual void setTransformedAABB_(int upper_xPos, int upper_yPos, int upper_width_scaled, int upper_height_scaled, float scale);
};

}