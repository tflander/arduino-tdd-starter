#ifndef ADAFRUIT_NEOPIXEL_H
#define ADAFRUIT_NEOPIXEL_H

#include "Arduino.h"

#define NEO_GRB  ((1<<6) | (1<<4) | (0<<2) | (2)) ///< Transmit as G,R,B
#define NEO_KHZ800 0x0000 ///< 800 KHz data transmission
typedef uint16_t neoPixelType; ///< 3rd arg to Adafruit_NeoPixel constructor

class Adafruit_NeoPixel {

 public:
  Adafruit_NeoPixel(uint16_t n, uint16_t pin=6,
    neoPixelType type=NEO_GRB + NEO_KHZ800);
    void show(void);
    void setPixelColor(uint16_t n, uint32_t c);
    void setBrightness(uint8_t);
};

#endif // ADAFRUIT_NEOPIXEL_H
