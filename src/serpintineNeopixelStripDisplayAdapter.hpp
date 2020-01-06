#ifndef _SERPINTINE_NEOPIXEL_STRIP_DISPLAY_ADAPTER_H_
#define _SERPINTINE_NEOPIXEL_STRIP_DISPLAY_ADAPTER_H_

#include "abstractDisplayAdapter.hpp"
#include "Adafruit_NeoPixel.h"

class SerpintineNeopixelStripDisplayAdapter : AbstractDisplayAdapter {

    public:

        SerpintineNeopixelStripDisplayAdapter(Adafruit_NeoPixel& strip);
        void display(struct Grid grid);

    // private:

        static void preDisplay(Adafruit_NeoPixel& strip);
        static void postDisplay(Adafruit_NeoPixel& strip);
        static void displayCell(Adafruit_NeoPixel& strip, struct Point point, char mark);
        static void endRow(Adafruit_NeoPixel& strip);

        Adafruit_NeoPixel strip;

};

#endif