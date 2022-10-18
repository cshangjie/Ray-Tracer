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

Tuple operator+(const Tuple lhs, const Tuple rhs){
    const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(), 
      lhs.y() - rhs.y(), 
      lhs.z() - rhs.z(), 
      lhs.w() - rhs.w());
}
Tuple operator-(const Tuple lhs, const Tuple rhs){
    const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(), 
      lhs.y() - rhs.y(), 
      lhs.z() - rhs.z(), 
      lhs.w() - rhs.w());
}
Tuple operator*(const Tuple lhs, const Tuple rhs){
    const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(), 
      lhs.y() - rhs.y(), 
      lhs.z() - rhs.z(), 
      lhs.w() - rhs.w());
}
Tuple operator/(const Tuple lhs, const Tuple rhs){
    const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(), 
      lhs.y() - rhs.y(), 
      lhs.z() - rhs.z(), 
      lhs.w() - rhs.w());
}
// Tuple operator==(const Tuple lhs, const Tuple rhs){
//     const auto tuplePoint = new Tuple(
//       lhs.x() - rhs.x(), 
//       lhs.y() - rhs.y(), 
//       lhs.z() - rhs.z(), 
//       lhs.w() - rhs.w());
// }

