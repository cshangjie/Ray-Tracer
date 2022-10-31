#include <gtest/gtest.h>
#include <cmath>
#include "../src/Math.h"
#include "../src/Color.h"
#include "../src/Canvas.h"

class CanvasTest : public::testing::Test{
    protected:
    CanvasTest(){};
    ~CanvasTest(){};
};

// every pixel should be black aka 0,0,0
TEST(CanvasTest, CanvasConstructorTest){
    const auto canvas = Canvas(10, 20);
    ASSERT_EQ(canvas.Width(), 10);
    ASSERT_EQ(canvas.Height(), 20);
    for(int x = 0; x < canvas.Width() - 1; x++){
        for(int y = 0; y < canvas.Height() - 1; y++){
            ASSERT_TRUE(Color(0, 0, 0) == canvas.PixelAt(x, y));
        }
    }
}