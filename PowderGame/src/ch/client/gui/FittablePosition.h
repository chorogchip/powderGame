#pragma once

#include "../../utils/EnumSides.h"
#include "../../utils/AABB.h"


namespace ch {

class FittablePosition {

public:
  FittablePosition(ch::EnumSides side, float xGap, float yGap, float width, float height);
  ~FittablePosition();

  void setTransformedAABB(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale);

  inline void setTransformedAABB(sfAABB aabb, float scale) {
    this->setTransformedAABB(aabb.pos.x, aabb.pos.y, aabb.size.x, aabb.size.y, scale);
  }

  inline float get_xGap() const {
    return xGap_;
  }
  inline float get_yGap() const {
    return yGap_;
  }
  inline float get_width() const {
    return width_;
  }
  inline float get_height() const {
    return height_;
  }
  inline const ch::sfAABB& getTransformedAABB() const {
    return transformedAABB_;
  }

  inline void setPosision(float x, float y, float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {
    xGap_ = x;
    yGap_ = y;
    setTransformedAABB(upper_xPos, upper_yPos, upper_width_scaled, upper_height_scaled, scale);
  }
  inline void setPosision(float x, float y, sfAABB aabb, float scale) {
    xGap_ = x;
    yGap_ = y;
    setTransformedAABB(aabb, scale);
  }
  inline void setSize(float x, float y, float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale) {
    width_ = x;
    height_ = y;
    setTransformedAABB(upper_xPos, upper_yPos, upper_width_scaled, upper_height_scaled, scale);
  }

private:

  ch::EnumSides side_;
  float xGap_;
  float yGap_;
  float width_;
  float height_;
  ch::sfAABB transformedAABB_;
  virtual void setTransformedAABB_(float upper_xPos, float upper_yPos, float upper_width_scaled, float upper_height_scaled, float scale);


};

}