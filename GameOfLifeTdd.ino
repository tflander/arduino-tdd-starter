#include <Adafruit_NeoPixel.h>

extern "C" {
  #include <neopixel_adapter.h>
  #include <render.h>
  #include <gameOfLife.h>
}
#include <serpintineNeopixelStripDisplayAdapter.hpp>

#define LED_PIN 6

uint32_t liveColor = Adafruit_NeoPixel::Color(0,0,255);
uint32_t deadColor = Adafruit_NeoPixel::Color(64,0,0);
const int numCols = 23;
const int numRows = 10;
char gridData[numRows][numCols];
struct Grid grid = (struct Grid){(char*)gridData, numRows, numCols};
Adafruit_NeoPixel strip;

//void preDisplay();
//void postDisplay();
//void displayCell(struct Point point, char mark);
//void endRow();

SerpintineNeopixelStripDisplayAdapter displayAdapter;

void setup() {
  Serial.begin(9600);
  delay(analogRead(0));
  
  randomizeGrid(grid, analogRead(0));
  strip = Adafruit_NeoPixel(numRows * numCols, LED_PIN, NEO_GRB + NEO_KHZ800);
  strip.setBrightness(20);
  strip.begin();

SerpintineNeopixelStripDisplayAdapter::setStrip(&strip);
//  struct displayFunctionPointers fp;
//
//  fp.displayCellFunction = displayCell;
//  fp.preDisplayFunction = noop;
//  fp.endRowFunction = noop;
//  fp.postDisplayFunction = postDisplay;
}
 
void loop() {
  displayAdapter.display(grid);
  tick(grid);
  delay(1000);
}

//void noop() {
//}
//
//void postDisplay() {
//    strip.show();
//}
//
//void displayCell(struct Point point, char mark) {
//  int pixel = strandOffsetForPoint(grid, point);
//  strip.setPixelColor(pixel, mark=='X' ? liveColor : deadColor);
//}
