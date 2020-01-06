#ifndef _SERPINTINE_NEOPIXEL_STRIP_DISPLAY_ADAPTER_H_
#define _SERPINTINE_NEOPIXEL_STRIP_DISPLAY_ADAPTER_H_

#include "abstractDisplayAdapter.hpp"
#include "Adafruit_NeoPixel.h"

class SerpintineNeopixelStripDisplayAdapter : AbstractDisplayAdapter {

    public:

        static Adafruit_NeoPixel* strip;
        static struct Grid* grid;
        static uint32_t liveColor;
        static uint32_t deadColor;

        void display(struct Grid);

        static void setStrip(Adafruit_NeoPixel*);

    private:

        static void preDisplay();
        static void postDisplay();
        static void displayCell(struct Point point, char mark);
        static void endRow();


};

#endif