#ifndef MATH_H_
#define MATH_H_
#include <stdlib.h>

// Account for round-off error when testing for equivalence
const float EPSILON = 0.00001;

inline bool equals(float num1, float num2){
    return abs(num1-num2) < EPSILON;
};

#endif    // MATH_H_