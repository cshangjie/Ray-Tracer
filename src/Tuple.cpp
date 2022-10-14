#include "Tuple.hpp"
#include "Math.hpp"
#include <string>

Tuple::Tuple(float x, float y, float z, float w) {
  x_ = x;
  y_ = y;
  z_ = z;
  w_ = w;
};

bool Tuple::IsPoint() const{
  return equals(1.0, w_);
}

bool Tuple::IsVector() const{
  return equals(0.0, w_);
}