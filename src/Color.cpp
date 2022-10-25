#include "Color.h"
#include <math.h>


Color::Color(float r, float g, float b) : Tuple(r, g, b, 0) {}

Color operator*(const Color c1, const Color c2)
{
  return Color(c1.r() * c2.r(), c1.g() * c2.g(), c1.b() * c2.b());
}

Color operator*(const Color c, float scalar)
{
  return Color(c.r() * scalar, c.g() * scalar, c.b() * scalar);
}

Color operator+(const Color c1, const Color c2)
{
  return Color(c1.r() + c2.r(), c1.g() + c2.g(), c1.b() + c2.b());
}

Color operator-(const Color &c1, const Color &c2)
{
  return Color(c1.r() - c2.r(), c1.g() - c2.g(), c1.b() - c2.b());
}