#include <Adafruit_NeoPixel.h>

#define PIN_NEO_PIXEL_1 0 // Arduino pin that connects to NeoPixel 1
#define PIN_NEO_PIXEL_2 5 // Arduino pin that connects to NeoPixel 2
#define PIN_NEO_PIXEL_3 1 // Arduino pin that connects to NeoPixel 3
#define PIN_NEO_PIXEL_4 2 // Arduino pin that connects to NeoPixel 4
#define NUM_PIXELS 60     // The number of LEDs (pixels) on each NeoPixel

Adafruit_NeoPixel strip1(NUM_PIXELS, PIN_NEO_PIXEL_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_PIXELS, PIN_NEO_PIXEL_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(NUM_PIXELS, PIN_NEO_PIXEL_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(NUM_PIXELS, PIN_NEO_PIXEL_4, NEO_GRB + NEO_KHZ800);

void setup() {
  strip1.begin();
  strip2.begin();
  strip3.begin();
  strip4.begin();
}

void loop() {
 // Set all pixels to red on strip 1
 for (int i = 0; i < NUM_PIXELS; i++) {
   int r = random(0, 256);
   int g = random(0, 256);
   int b = random(0, 256);
   strip1.setPixelColor(i, strip1.Color(r, g, b));
 }
 strip1.show();

 // Set all pixels to green on strip 2
 for (int i = 0; i < NUM_PIXELS; i++) {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);
  strip2.setPixelColor(i, strip2.Color(r, g, b));
 }
 strip2.show();

 // Set all pixels to green on strip 3
 
 for (int i = NUM_PIXELS; i >= 0; i--) {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);
  strip3.setPixelColor(i, strip3.Color(r, g, b));
 }
 strip3.show();
 
  // Set all pixels to green on strip 4
 for (int i = NUM_PIXELS; i >= 0; i--) {
  int r = random(0, 256);
  int g = random(0, 256);
  int b = random(0, 256);
  strip4.setPixelColor(i, strip4.Color(r, g, b));
  delay(40);
 }
 strip4.show();

 delay(1000);
}