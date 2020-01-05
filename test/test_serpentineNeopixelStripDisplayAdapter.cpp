#include <gtest/gtest.h>

extern "C" {
    #include "render.h"
}
#include "serpintineNeopixelStripDisplayAdapter.hpp"

class SerpintineNeopixelDisplayAdapterTest : public ::testing::Test {

    protected:

        const static int numColsForGridTests = 4;
        const static int numRowsForGridTests = 3;
        char gridData[numRowsForGridTests][numColsForGridTests];
        struct Grid grid;

        SerpintineNeopixelDisplayAdapterTest() {
            grid = (struct Grid){(char*)gridData, numRowsForGridTests, numColsForGridTests};
            wipeGrid(grid);
        }
};

TEST_F(SerpintineNeopixelDisplayAdapterTest, display)
{
    SerpintineNeopixelStripDisplayAdapter displayAdapter;
    displayAdapter.display(grid);
    ASSERT_EQ(0, 0);
}
