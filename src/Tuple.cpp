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

Tuple Tuple::Normalize() const
{
  float mag = this->Magnitude();
  return Tuple(this->x() / mag, this->y() / mag, this->z() / mag, this->w() / mag);
}

float Tuple::Dot(Tuple tuple) const
{
  return this->x() * tuple.x() +
         this->y() * tuple.y() +
         this->z() * tuple.z() +
         this->w() * tuple.w();
}

Tuple operator+(const Tuple lhs, const Tuple rhs)
{
  return Tuple(
      lhs.x() + rhs.x(),
      lhs.y() + rhs.y(),
      lhs.z() + rhs.z(),
      lhs.w() + rhs.w());
}
Tuple operator-(const Tuple lhs, const Tuple rhs)
{
  return Tuple(
      lhs.x() - rhs.x(),
      lhs.y() - rhs.y(),
      lhs.z() - rhs.z(),
      lhs.w() - rhs.w());
}
/* 
 *  Doesn't multiply the flag for vector vs point identification
 */
Tuple operator*(const Tuple lhs, float scalar)
{
  return Tuple(
      lhs.x() * scalar,
      lhs.y() * scalar,
      lhs.z() * scalar,
      lhs.w());
}
/* 
 *  Doesn't divide the flag for vector vs point identification
 */
Tuple operator/(const Tuple tuple, float scalar)
{
  return tuple * (1/scalar);
}
bool operator==(const Tuple lhs, const Tuple rhs)
{
  return equals(lhs.x(), rhs.x()) &&
         equals(lhs.y(), rhs.y()) &&
         equals(lhs.z(), rhs.z());
}
Tuple operator-(const Tuple tuple)
{
  return Tuple(-tuple.x(), -tuple.y(), -tuple.z(), -tuple.w());
}