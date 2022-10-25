#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include "../src/Math.h"
#include "../src/Point.h"

class PointTest : public ::testing::Test
{
protected:
  PointTest(){};
  ~PointTest(){};
};

TEST(PointTest, VectorConstructorTest)
{
  const auto v1 = Point(3.4, -2.3, 1.2);

  EXPECT_FLOAT_EQ(v1.x(), 3.4);
  EXPECT_FLOAT_EQ(v1.y(), -2.3);
  EXPECT_FLOAT_EQ(v1.z(), 1.2);
  EXPECT_FLOAT_EQ(v1.w(), 1);

  const auto v2 = Point(0.0, 0.0, 0.0);

  EXPECT_FLOAT_EQ(v2.x(), 0.0);
  EXPECT_FLOAT_EQ(v2.y(), 0.0);
  EXPECT_FLOAT_EQ(v2.z(), 0.0);
  EXPECT_FLOAT_EQ(v2.w(), 1);
}