#ifndef MATH_H_
#define MATH_H_
#include <stdlib.h>

// Account for round-off error when testing for equivalence
const float EPSILON = 0.0001;

inline bool Equals(float num1, float num2){
    return abs(num1-num2) < EPSILON;
};

inline float FastInvSqrt( float number )
{
	long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = number * 0.5F;
	y  = number;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}

#endif    // MATH_H_