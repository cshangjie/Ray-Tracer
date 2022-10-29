#include <gtest/gtest.h>
#include <cmath>
#include "../src/Math.h"
#include "../src/Color.h"

class CanvasTest : public::testing::Test{
    protected:
    CanvasTest(){};
    ~CanvasTest(){};
};

TEST(CanvasTest, CanvasConstructorTest){
    const auto canvas = Canvas(10, 20);

    ASSERT_EQ(canvas.Width(), 10);
    ASSERT_EQ(canvas.Height(), 20);
    for(int i = 0; i < canvas.Width() - 1; i++){
        for(int j = 0; j < canvas.Height() - 1; j++){
            ASSERT_TRUE(Color(0, 0, 0) == canvas.PixelAt(i, j));
        }
    }

}