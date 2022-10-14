#include <gtest/gtest.h>
#include "../src/Tuple.hpp"


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

TEST(TupleTest, test) {
  const auto tupleVec = new Tuple(3.4, -2.3, 1.2, 0.0);
  
  EXPECT_FLOAT_EQ(tupleVec->x(), 3.4);
  EXPECT_FLOAT_EQ(tupleVec->y(), -2.3);
  EXPECT_FLOAT_EQ(tupleVec->z(), 1.2);
  EXPECT_FLOAT_EQ(tupleVec->w(), 0.0);

  EXPECT_TRUE(tupleVec->IsVector());
  EXPECT_FALSE(tupleVec->IsPoint());
}
