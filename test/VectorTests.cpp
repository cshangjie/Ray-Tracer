#include <gtest/gtest.h>
#include <cmath>
#include "../src/Math.h"
#include "../src/Vector.h"

class VectorTest : public::testing::Test
{
protected:
  VectorTest(){};
  ~VectorTest(){};
};

TEST(VectorTest, VectorConstructorTest)
{
  const auto v1 = Vector(3.4, -2.3, 1.2);

  EXPECT_FLOAT_EQ(v1.x(), 3.4);
  EXPECT_FLOAT_EQ(v1.y(), -2.3);
  EXPECT_FLOAT_EQ(v1.z(), 1.2);
  EXPECT_FLOAT_EQ(v1.w(), 0);

  const auto v2 = Vector(0.0, 0.0, 0.0);

  EXPECT_FLOAT_EQ(v2.x(), 0.0);
  EXPECT_FLOAT_EQ(v2.y(), 0.0);
  EXPECT_FLOAT_EQ(v2.z(), 0.0);
  EXPECT_FLOAT_EQ(v2.w(), 0);
}

TEST(VectorTest, TestMagnitude)
{
  const auto vec1 = Vector(1, 0, 0);
  const auto magnitude1 = vec1.Magnitude();
  ASSERT_FLOAT_EQ(magnitude1, 1);

  const auto tuple2 = Vector(1, 0, 0);
  ASSERT_FLOAT_EQ(tuple2.Magnitude(), 1);

  const auto tuple3 = Vector(0, 0, 1);
  ASSERT_FLOAT_EQ(tuple3.Magnitude(), 1);

  // checks the FastInvSqrt function
  const auto tuple4 = Vector(3.4, -2.3, 1.2);
  const auto invSqrt = FastInvSqrt((3.4 * 3.4) + (-2.3 * -2.3) + (1.2 * 1.2) + (0.0 * 0.0));
  ASSERT_FLOAT_EQ(1 / tuple4.Magnitude(), invSqrt);
}
TEST(VectorTest, TestNormalize)
{
  const auto vec1 = Vector(4, 0, 0);
  const auto normalizedVec1 = vec1.Normalize();
  ASSERT_TRUE(vec1.Normalize() == Vector(1, 0, 0));

  const auto vec2 = Vector(1, 2, 3);
  ASSERT_TRUE(vec2.Normalize() == Vector(0.26726, 0.53452, 0.80178));
}
TEST(VectorTest, TestDot)
{
  const auto vec1 = Vector(1, 2, 3);
  const auto vec2 = Vector(2, 3, 4);
  ASSERT_FLOAT_EQ(vec1.Dot(vec2), 20);
}
