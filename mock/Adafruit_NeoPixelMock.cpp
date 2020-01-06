#include "Adafruit_NeoPixel.h"

Adafruit_NeoPixel::Adafruit_NeoPixel(uint16_t n, uint16_t pin, neoPixelType type) {
    reset();
}

void Adafruit_NeoPixel::show(void) {
    showCalled = true;
}

void Adafruit_NeoPixel::setPixelColor(uint16_t n, uint32_t c) {
    struct pixel element{.n=n, .c=c};
    pixelValues.push_back(element);
}

void Adafruit_NeoPixel::setBrightness(uint8_t v) {
    brightnessValue = v;
}

void Adafruit_NeoPixel::reset() {
    showCalled = false;
    pixelValues.clear();
}
