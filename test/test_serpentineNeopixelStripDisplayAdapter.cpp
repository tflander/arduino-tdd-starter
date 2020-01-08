#include <gtest/gtest.h>

extern "C" {
    #include "render.h"
}
#include "serpintineNeopixelStripDisplayAdapter.hpp"
#include "support.hpp"

class SerpintineNeopixelDisplayAdapterTest : public BaseGridTest {

    protected:

        const static int LED_PIN = 6;
        const static int numRows = 3;
        const static int numCols = 4;
        SerpintineNeopixelDisplayAdapterTest() : BaseGridTest(numRows, numCols) {}
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(numRows * numCols, LED_PIN, NEO_GRB + NEO_KHZ800);
};

int countPixelsAndVerifyAllDead(SerpintineNeopixelStripDisplayAdapter& displayAdapter, Adafruit_NeoPixel& strip);

TEST_F(SerpintineNeopixelDisplayAdapterTest, display)
{
    SerpintineNeopixelStripDisplayAdapter displayAdapter;
    SerpintineNeopixelStripDisplayAdapter::setStrip(&strip);
    displayAdapter.display(grid);

    ASSERT_TRUE(strip.showCalled);
    int writtenPixelCount = countPixelsAndVerifyAllDead(displayAdapter, strip);
    ASSERT_EQ(grid.numCols * grid.numRows, writtenPixelCount);

}

void ASSERT_PIXEL_COLOR(uint32_t expectedColor, uint32_t actualColor) {
    ASSERT_EQ(expectedColor, actualColor);
}

int countPixelsAndVerifyAllDead(SerpintineNeopixelStripDisplayAdapter& displayAdapter, Adafruit_NeoPixel& strip) {
    uint32_t deadColor = displayAdapter.deadColor; 
    int writtenPixelCount = 0;
    for (list<pixel>::iterator it=strip.pixelValues.begin(); it != strip.pixelValues.end(); ++it) {
        uint32_t pixelColor = it->c;
        ++writtenPixelCount;
        ASSERT_PIXEL_COLOR(deadColor, pixelColor);
    }
    return writtenPixelCount;
}
