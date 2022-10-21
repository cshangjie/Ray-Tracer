#include "Tuple.hpp"
#include "Math.hpp"
#include <string>
#include <cmath>

Tuple::Tuple(float x, float y, float z, float w)
{
  x_ = x;
  y_ = y;
  z_ = z;
  w_ = w;
};

bool Tuple::IsPoint() const
{
  return equals(1.0, w_);
}

bool Tuple::IsVector() const
{
  return equals(0.0, w_);
}

float Tuple::Magnitude() const
{
  return std::sqrt(this->x() * this->x() + 
                   this->y() * this->y() + 
                   this->z() * this->z() + 
                   this->w() + this->w());
}
Tuple Tuple::Normalize() const{
  float mag = this->Magnitude();
  return Tuple(this->x()/mag, this->y()/mag, this->z()/mag, this->w()/mag);
}


Tuple operator+(const Tuple lhs, const Tuple rhs)
{
  const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(),
      lhs.y() - rhs.y(),
      lhs.z() - rhs.z(),
      lhs.w() - rhs.w());
}
Tuple operator-(const Tuple lhs, const Tuple rhs)
{
  const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(),
      lhs.y() - rhs.y(),
      lhs.z() - rhs.z(),
      lhs.w() - rhs.w());
}
Tuple operator*(const Tuple lhs, const Tuple rhs)
{
  const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(),
      lhs.y() - rhs.y(),
      lhs.z() - rhs.z(),
      lhs.w() - rhs.w());
}
Tuple operator/(const Tuple lhs, const Tuple rhs)
{
  const auto tuplePoint = new Tuple(
      lhs.x() - rhs.x(),
      lhs.y() - rhs.y(),
      lhs.z() - rhs.z(),
      lhs.w() - rhs.w());
}
bool operator==(const Tuple lhs, const Tuple rhs)
{
  return equals(lhs.x(), rhs.x()) &&
         equals(lhs.y(), rhs.y()) &&
         equals(lhs.z(), rhs.z());
}
