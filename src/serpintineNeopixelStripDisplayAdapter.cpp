#include "serpintineNeopixelStripDisplayAdapter.hpp"

extern "C" {
    #include "render.h"
}

Adafruit_NeoPixel* SerpintineNeopixelStripDisplayAdapter::strip = 0;

void SerpintineNeopixelStripDisplayAdapter::setStrip(Adafruit_NeoPixel* s) {
    SerpintineNeopixelStripDisplayAdapter::strip = s;
}

void SerpintineNeopixelStripDisplayAdapter::display(struct Grid grid) {
    struct displayFunctionPointers fp = {
        .displayCellFunction = displayCell,
        .preDisplayFunction = preDisplay,
        .endRowFunction = endRow,
        .postDisplayFunction = postDisplay

    };

    ::display(grid, fp);

}

void SerpintineNeopixelStripDisplayAdapter::preDisplay() {

}

void SerpintineNeopixelStripDisplayAdapter::postDisplay() {
    strip->show();
}

void SerpintineNeopixelStripDisplayAdapter::displayCell(struct Point point, char mark) {

}

void SerpintineNeopixelStripDisplayAdapter::endRow() {

}
