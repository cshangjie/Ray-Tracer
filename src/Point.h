#ifndef RT_Point_H_
#define RT_Point_H_

#include "Tuple.h"

class Point : public Tuple {
 public:
  Point() {};
  Point(float x, float y, float z);
  ~Point() = default;
};

#endif /* RT_POINT_H_ */