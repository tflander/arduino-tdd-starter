#include <gtest/gtest.h>
#include <stdbool.h>

extern "C" {
    #include "neopixel_adapter.h"
    #include "gameOfLife.h"
}
#include "support.hpp"

class NeopixelAdapterTest : public BaseGridTest {

    protected:

        const static int numRows = 4;
        const static int numCols = 5;
        NeopixelAdapterTest() : BaseGridTest(numRows, numCols) {}
};

TEST_F(NeopixelAdapterTest, point_0_0_is_neopixel_0)
{
    ASSERT_EQ(0, strandOffsetForPoint(grid, (struct Point){.x=0, .y=0}));
}

TEST_F(NeopixelAdapterTest, point_1_0_is_neopixel_1)
{
    ASSERT_EQ(1, strandOffsetForPoint(grid, (struct Point){.x=1, .y=0}));
}

TEST_F(NeopixelAdapterTest, point_4_0_is_neopixel_4)
{
    ASSERT_EQ(4, strandOffsetForPoint(grid, (struct Point){.x=4, .y=0}));
}

TEST_F(NeopixelAdapterTest, point_4_1_is_neopixel_5)
{
    ASSERT_EQ(5, strandOffsetForPoint(grid, (struct Point){.x=4, .y=1}));
}

TEST_F(NeopixelAdapterTest, point_3_1_is_neopixel_6)
{
    ASSERT_EQ(6, strandOffsetForPoint(grid, (struct Point){.x=3, .y=1}));
}

TEST_F(NeopixelAdapterTest, point_0_1_is_neopixel_9)
{
    ASSERT_EQ(9, strandOffsetForPoint(grid, (struct Point){.x=0, .y=1}));
}

TEST_F(NeopixelAdapterTest, point_0_2_is_neopixel_10)
{
    ASSERT_EQ(10, strandOffsetForPoint(grid, (struct Point){.x=0, .y=2}));
}

