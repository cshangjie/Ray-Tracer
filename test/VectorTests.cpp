#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include "../src/Tuple.h"
#include "../src/Math.h"
#include "../src/Vector.h"


TEST(TupleTest, TestMagnitude)
{
  const auto tuple1 = Tuple(1, 0, 0, 0.0);
  const auto magnitude1 = tuple1.Magnitude();
  ASSERT_FLOAT_EQ(tuple1.Magnitude(), 1);

  const auto tuple2 = Tuple(1, 0, 0, 0.0);
  ASSERT_FLOAT_EQ(tuple2.Magnitude(), 1);

  const auto tuple3 = Tuple(0, 0, 1, 0.0);
  ASSERT_FLOAT_EQ(tuple3.Magnitude(), 1);

  const auto tuple4 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto invSqrt = FastInvSqrt((3.4 * 3.4) + (-2.3 * -2.3) + (1.2 * 1.2) + (0.0 * 0.0));
  ASSERT_FLOAT_EQ(1/tuple4.Magnitude(), invSqrt);
}
TEST(TupleTest, TestNormalize)
{
  const auto vec1 = Vector(4, 0, 0);
  const auto normalizedVec1 = vec1.Normalize();
  ASSERT_TRUE(vec1.Normalize() == Vector(1, 0, 0));

  const auto vec2 = Vector(1, 2, 3);
  ASSERT_TRUE(vec2.Normalize() == Vector(0.26726, 0.53452, 0.80178));
}
TEST(TupleTest, TestDot)
{
  const auto vec1 = Vector(1, 2, 3);
  const auto vec2 = Vector(2, 3, 4);
  ASSERT_FLOAT_EQ(vec1.Dot(vec2), 20);
}
