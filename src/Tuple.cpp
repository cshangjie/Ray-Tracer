#include "Tuple.h"
#include "Math.h"
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
  return Equals(1.0, w_);
}

bool Tuple::IsVector() const
{
  return Equals(0.0, w_);
}

/**
 * @brief not currently used but returns the magnitude used in vector normalizing
 * 
 * @return float 
 */
float Tuple::Magnitude() const
{
  return std::sqrt(this->x() * this->x() +
                   this->y() * this->y() +
                   this->z() * this->z() +
                   this->w() * this->w());
}

Tuple Tuple::Normalize() const
{
  float invSqrt = FastInvSqrt(this->x() * this->x() +
                   this->y() * this->y() +
                   this->z() * this->z() +
                   this->w() * this->w());
  return Tuple(this->x() * invSqrt, this->y() * invSqrt, this->z() * invSqrt, this->w() / invSqrt);
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
  return Equals(lhs.x(), rhs.x()) &&
         Equals(lhs.y(), rhs.y()) &&
         Equals(lhs.z(), rhs.z());
}
Tuple operator-(const Tuple tuple)
{
  return Tuple(-tuple.x(), -tuple.y(), -tuple.z(), -tuple.w());
}
