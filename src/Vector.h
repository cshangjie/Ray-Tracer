#ifndef RT_VECTOR_H_
#define RT_VECTOR_H_

#include "Tuple.h"

class Vector : public Tuple {
 public:
  Vector() {};
  Vector(float x, float y, float z);
  ~Vector() = default;

  float x() const { return this->x(); }
  float y() const { return this->y(); }
  float z() const { return this->z(); }
};

#endif    // RT_VECTOR_H_