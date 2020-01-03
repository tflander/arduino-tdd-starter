// Mock version of Arduino.h which defines commonn registers as variables.

#ifndef _arduino_h_
#define _arduino_h_

#include <stdint.h>

// typedef uint8_t byte ;

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
int digitalRead(uint8_t pin);
uint32_t analogRead( uint32_t ulPin );

#endif