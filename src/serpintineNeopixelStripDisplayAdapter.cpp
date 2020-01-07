#include "serpintineNeopixelStripDisplayAdapter.hpp"

extern "C" {
    #include "render.h"
    #include "neopixel_adapter.h"
}

Adafruit_NeoPixel* SerpintineNeopixelStripDisplayAdapter::strip = 0;
struct Grid* SerpintineNeopixelStripDisplayAdapter::grid = 0;
uint32_t SerpintineNeopixelStripDisplayAdapter::liveColor = Adafruit_NeoPixel::Color(0,0,255);;
uint32_t SerpintineNeopixelStripDisplayAdapter::deadColor = Adafruit_NeoPixel::Color(128,0,0);;

void SerpintineNeopixelStripDisplayAdapter::setStrip(Adafruit_NeoPixel* s) {
    SerpintineNeopixelStripDisplayAdapter::strip = s;
}

void SerpintineNeopixelStripDisplayAdapter::display(struct Grid g) {
    struct displayFunctionPointers fp;
    fp.displayCellFunction = displayCell;
    fp.preDisplayFunction = preDisplay;
    fp.endRowFunction = endRow;
    fp.postDisplayFunction = postDisplay;

    SerpintineNeopixelStripDisplayAdapter::grid = &g;
    ::display(*SerpintineNeopixelStripDisplayAdapter::grid, fp);

}

void SerpintineNeopixelStripDisplayAdapter::preDisplay() {

}

void SerpintineNeopixelStripDisplayAdapter::postDisplay() {
    strip->show();
}

void SerpintineNeopixelStripDisplayAdapter::displayCell(struct Point point, char mark) {
  uint16_t pixel = strandOffsetForPoint(*grid, point);
  strip->setPixelColor(pixel, mark=='X' ? liveColor : deadColor);
}

void SerpintineNeopixelStripDisplayAdapter::endRow() {

}
