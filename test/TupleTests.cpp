#include <gtest/gtest.h>
#include "../src/Tuple.hpp"
#include "../src/Math.hpp"


class TupleTest : public ::testing::Test {
 protected:
  TupleTest() {};
  ~TupleTest() {};
};

TEST(TupleTest, TestPoint){
  const auto tuplePoint = new Tuple(3.4, -2.3, 1.2, 1.0);

  EXPECT_FLOAT_EQ(tuplePoint->x(), 3.4);
  EXPECT_FLOAT_EQ(tuplePoint->y(), -2.3);
  EXPECT_FLOAT_EQ(tuplePoint->z(), 1.2);
  EXPECT_FLOAT_EQ(tuplePoint->w(), 1.0);
  
  EXPECT_TRUE(tuplePoint->IsPoint());
  EXPECT_FALSE(tuplePoint->IsVector());

}

TEST(TupleTest, TestVec) {
  const auto tupleVec = new Tuple(3.4, -2.3, 1.2, 0.0);
  
  EXPECT_FLOAT_EQ(tupleVec->x(), 3.4);
  EXPECT_FLOAT_EQ(tupleVec->y(), -2.3);
  EXPECT_FLOAT_EQ(tupleVec->z(), 1.2);
  EXPECT_FLOAT_EQ(tupleVec->w(), 0.0);

  EXPECT_TRUE(tupleVec->IsVector());
  EXPECT_FALSE(tupleVec->IsPoint());
}

TEST(TupleTest, TestAdd) {
  const auto tuple1 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto tuple2 = Tuple(1.5, 3.3, -4.2, 1.0);
  const auto resultTuple = tuple1 + tuple2;

  EXPECT_FLOAT_EQ(resultTuple.x(), float(3.4 + 1.5));
  EXPECT_FLOAT_EQ(resultTuple.y(), float((-2.3) + 3.3));
  EXPECT_FLOAT_EQ(resultTuple.z(), float(1.2 + (-4.2)));
  EXPECT_FLOAT_EQ(resultTuple.w(), float(0.0 + 1.0));
}

TEST(TupleTest, TestSubtract) {
  const auto tuple1 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto tuple2 = Tuple(1.5, 3.3, -4.2, 1.0);
  const auto resultTuple = tuple1 - tuple2;
  
  EXPECT_FLOAT_EQ(resultTuple.x(), 3.4 - 1.5);
  EXPECT_FLOAT_EQ(resultTuple.y(), -2.3 - 3.3);
  EXPECT_FLOAT_EQ(resultTuple.z(), 1.2 - (-4.2));
  EXPECT_FLOAT_EQ(resultTuple.w(), 0.0 - 1.0);
}

TEST(TupleTest, TestNegate) {
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto negatedTuple = -tuple;
  EXPECT_FLOAT_EQ(negatedTuple.x(), -3.4);
  EXPECT_FLOAT_EQ(negatedTuple.y(), 2.3);
  EXPECT_FLOAT_EQ(negatedTuple.z(), -1.2);
  EXPECT_FLOAT_EQ(negatedTuple.w(), 0.0);
}

TEST(TupleTest, TestScalarMultiply) {
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);
  
  const auto resultTuple = tuple * 2.35;

  EXPECT_FLOAT_EQ(resultTuple.x(), 3.4 * 2.35);
  EXPECT_FLOAT_EQ(resultTuple.y(), -2.3 * 2.35);
  EXPECT_FLOAT_EQ(resultTuple.z(), 1.2 * 2.35);
  EXPECT_FLOAT_EQ(resultTuple.w(), 0.0);
}

TEST(TupleTest, TestScalarDivide) {
  const auto tuple = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto result = tuple/5.3;
  EXPECT_FLOAT_EQ(result.x(), 3.4/5.3);
  EXPECT_FLOAT_EQ(result.y(), -2.3/5.3);
  EXPECT_FLOAT_EQ(result.z(), 1.2/5.3);
  EXPECT_FLOAT_EQ(result.w(), 0.0);
}

TEST(TupleTest, TestEquality) {
  const auto tuple1 = Tuple(3.4, -2.3, 1.2, 0.0);
  const auto tuple2 = Tuple(3.4, -2.3, 1.2, 0.0);
  ASSERT_TRUE(tuple1 == tuple2);
  // properly accounts of float precision
  ASSERT_FALSE(tuple1 == (tuple2 * float(1.0001)));
}
