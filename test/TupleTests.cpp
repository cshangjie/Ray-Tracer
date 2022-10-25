#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include "../src/Tuple.h"
#include "../src/Math.h"
#include "../src/Vector.h"
#include "../src/Point.h"

class TupleTest : public ::testing::Test
{
protected:
  TupleTest(){};
  ~TupleTest(){};
};

/*
  Constructor Tests & Tuple type checks
*/
TEST(TupleTest, Test_IsPoint_IsVector)
{
  const auto tuplePoint = new Tuple(3.4, -2.3, 1.2, 1.0);

  EXPECT_FLOAT_EQ(tuplePoint->x(), 3.4);
  EXPECT_FLOAT_EQ(tuplePoint->y(), -2.3);
  EXPECT_FLOAT_EQ(tuplePoint->z(), 1.2);
  EXPECT_FLOAT_EQ(tuplePoint->w(), 1.0);

  EXPECT_TRUE(tuplePoint->IsPoint());
  EXPECT_FALSE(tuplePoint->IsVector());

  const auto tupleVec = new Tuple(3.4, -2.3, 1.2, 0.0);

  EXPECT_FLOAT_EQ(tupleVec->x(), 3.4);
  EXPECT_FLOAT_EQ(tupleVec->y(), -2.3);
  EXPECT_FLOAT_EQ(tupleVec->z(), 1.2);
  EXPECT_FLOAT_EQ(tupleVec->w(), 0.0);

  EXPECT_TRUE(tupleVec->IsVector());
  EXPECT_FALSE(tupleVec->IsPoint());
}

TEST(TupleTest, Test_CreatePoint)
{
  const auto point = Point(1.1, 2.2, 3.3);

  EXPECT_FLOAT_EQ(point.x(), 1.1);
  EXPECT_FLOAT_EQ(point.y(), 2.2);
  EXPECT_FLOAT_EQ(point.z(), 3.3);
  EXPECT_FLOAT_EQ(point.w(), 1.0);

  EXPECT_TRUE(point.IsPoint());
  EXPECT_FALSE(point.IsVector());
}

TEST(TupleTest, Test_CreateVector)
{
  const auto vec = Point(1.1, 2.2, 3.3);

  EXPECT_FLOAT_EQ(vec.x(), 1.1);
  EXPECT_FLOAT_EQ(vec.y(), 2.2);
  EXPECT_FLOAT_EQ(vec.z(), 3.3);
  EXPECT_FLOAT_EQ(vec.w(), 1.0);

  EXPECT_TRUE(vec.IsPoint());
  EXPECT_FALSE(vec.IsVector());
}
/*
  Operator Testing
*/

TEST(TupleTest, TestAdd)
{
  const auto tuple1 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto tuple2 = Tuple(1.5, 3.3, -4.2, 1.0);
  const auto resultTuple = tuple1 + tuple2;

  EXPECT_FLOAT_EQ(resultTuple.x(), float(3.4 + 1.5));
  EXPECT_FLOAT_EQ(resultTuple.y(), float((-2.3) + 3.3));
  EXPECT_FLOAT_EQ(resultTuple.z(), float(1.2 + (-4.2)));
  EXPECT_FLOAT_EQ(resultTuple.w(), float(0.0 + 1.0));
}

TEST(TupleTest, TestSubtract)
{
  const auto tuple1 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto tuple2 = Tuple(1.5, 3.3, -4.2, 1.0);
  const auto resultTuple = tuple1 - tuple2;

  EXPECT_FLOAT_EQ(resultTuple.x(), 3.4 - 1.5);
  EXPECT_FLOAT_EQ(resultTuple.y(), -2.3 - 3.3);
  EXPECT_FLOAT_EQ(resultTuple.z(), 1.2 - (-4.2));
  EXPECT_FLOAT_EQ(resultTuple.w(), 0.0 - 1.0);
}

TEST(TupleTest, SubVectorFromZeroVector)
{
  const auto zero = Vector(0, 0, 0);
  const auto v = Vector(1, -2, 3);

  ASSERT_TRUE(zero - v == Vector(-1, 2, -3));
}

TEST(TupleTest, TestNegate)
{
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto negatedTuple = -tuple;
  EXPECT_FLOAT_EQ(negatedTuple.x(), -3.4);
  EXPECT_FLOAT_EQ(negatedTuple.y(), 2.3);
  EXPECT_FLOAT_EQ(negatedTuple.z(), -1.2);
  EXPECT_FLOAT_EQ(negatedTuple.w(), 0.0);
}

TEST(TupleTest, TestScalarMultiply)
{
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);

  const auto resultTuple = tuple * 2;

  EXPECT_FLOAT_EQ(resultTuple.x(), 6.8);
  EXPECT_FLOAT_EQ(resultTuple.y(), -4.6);
  EXPECT_FLOAT_EQ(resultTuple.z(), 2.4);
  EXPECT_FLOAT_EQ(resultTuple.w(), 0.0);
}
TEST(TupleTest, TestFractionScalarMultiply)
{
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);

  const auto resultTuple = tuple * 0.35;

  EXPECT_FLOAT_EQ(resultTuple.x(), 3.4 * 0.35);
  EXPECT_FLOAT_EQ(resultTuple.y(), -2.3 * 0.35);
  EXPECT_FLOAT_EQ(resultTuple.z(), 1.2 * 0.35);
  EXPECT_FLOAT_EQ(resultTuple.w(), 0.0);
}

TEST(TupleTest, TestScalarDivide)
{
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto result = tuple / 5.3;
  EXPECT_FLOAT_EQ(result.x(), 3.4 / 5.3);
  EXPECT_FLOAT_EQ(result.y(), -2.3 / 5.3);
  EXPECT_FLOAT_EQ(result.z(), 1.2 / 5.3);
  EXPECT_FLOAT_EQ(result.w(), 0.0);
}

TEST(TupleTest, TestEquality)
{
  const auto tuple1 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto tuple2 = Tuple(3.4, -2.3, 1.2, 0.0);
  ASSERT_TRUE(tuple1 == tuple2);
  // properly accounts of float precision
  ASSERT_FALSE(tuple1 == (tuple2 * float(1.001)));
}
