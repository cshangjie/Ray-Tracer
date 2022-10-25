#ifndef RT_COLOR_H_
#define RT_COLOR_H_

#include "Tuple.h"

class Color : public Tuple
{
public:
  Color(){};
  Color(float r, float g, float b);
  ~Color() = default;

  float r() const { return this->x(); }
  float g() const { return this->y(); }
  float b() const { return this->z(); }
};

/*
 *  Operator Overloads
 */
Color operator*(const Color c, const Color o);
Color operator*(const Color c, const float factor);
Color operator+(const Color c, const Color o);
Color operator-(const Color &c, const Color &o);

#endif // RT_COLOR_H_