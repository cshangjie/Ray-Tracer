#ifndef RT_Point_H_
#define RT_Point_H_

#include "Tuple.h"

class Point : public Tuple {
 public:
  Point() {};
  Point(float x, float y, float z);
  ~Point() = default;

  float x() const { return this->x(); }
  float y() const { return this->y(); }
  float z() const { return this->z(); }
};

#endif /* RT_POINT_H_ */