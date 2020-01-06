#include <gtest/gtest.h>

extern "C" {
    #include "render.h"
}
#include "serpintineNeopixelStripDisplayAdapter.hpp"

class SerpintineNeopixelDisplayAdapterTest : public ::testing::Test {

    protected:

        const static int LED_PIN = 6;
        const static int numCols = 4;
        const static int numRows = 3;
        char gridData[numRows][numCols];
        struct Grid grid;
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(numRows * numCols, LED_PIN, NEO_GRB + NEO_KHZ800);

        SerpintineNeopixelDisplayAdapterTest() {
            grid = (struct Grid){(char*)gridData, numRows, numCols};
            wipeGrid(grid);
        }
};

TEST_F(SerpintineNeopixelDisplayAdapterTest, display)
{
    SerpintineNeopixelStripDisplayAdapter displayAdapter;
    SerpintineNeopixelStripDisplayAdapter::setStrip(&strip);
    displayAdapter.display(grid);

    ASSERT_TRUE(strip.showCalled);
}
