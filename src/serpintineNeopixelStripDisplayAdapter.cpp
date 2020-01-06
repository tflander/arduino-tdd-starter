#include "serpintineNeopixelStripDisplayAdapter.hpp"
#include "render.h"

SerpintineNeopixelStripDisplayAdapter::SerpintineNeopixelStripDisplayAdapter(Adafruit_NeoPixel& s) 
    : strip(s) {
}

// voidFn* spike() {
//     return SerpintineNeopixelStripDisplayAdapter::preDisplay(0);
// }

void SerpintineNeopixelStripDisplayAdapter::display(struct Grid grid) {
    // struct displayFunctionPointers fp = {
    //     .displayCellFunction = displayCell,
    //     .preDisplayFunction = preDisplay,
    //     .endRowFunction = endRow,
    //     .postDisplayFunction = postDisplay

    // };

    // ::display(grid, fp);

    // voidFn* foo = &SerpintineNeopixelStripDisplayAdapter::preDisplay;
}

// typedef void (voidFn)(void);
// typedef void (displayCellFn)(struct Point point, char mark);

void SerpintineNeopixelStripDisplayAdapter::preDisplay(Adafruit_NeoPixel& strip) {

}

void SerpintineNeopixelStripDisplayAdapter::postDisplay(Adafruit_NeoPixel& strip) {
    strip.show();
}

void SerpintineNeopixelStripDisplayAdapter::displayCell(Adafruit_NeoPixel& strip, struct Point point, char mark) {

}

void SerpintineNeopixelStripDisplayAdapter::endRow(Adafruit_NeoPixel& strip) {

}
