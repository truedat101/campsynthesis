#include <Adafruit_NeoPixel.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define PIN_NEO_PIXEL_1 0 // Arduino pin that connects to NeoPixel 1
#define PIN_NEO_PIXEL_2 5 // Arduino pin that connects to NeoPixel 2
#define PIN_NEO_PIXEL_3 1 // Arduino pin that connects to NeoPixel 3
#define PIN_NEO_PIXEL_4 2 // Arduino pin that connects to NeoPixel 4
#define NUM_PIXELS 60     // The number of LEDs (pixels) on each NeoPixel

Adafruit_NeoPixel strip1(NUM_PIXELS, PIN_NEO_PIXEL_1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2(NUM_PIXELS, PIN_NEO_PIXEL_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(NUM_PIXELS, PIN_NEO_PIXEL_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(NUM_PIXELS, PIN_NEO_PIXEL_4, NEO_GRB + NEO_KHZ800);

// NeoPixel test program showing use of the WHITE channel for RGBW
// pixels only (won't look correct on regular RGB NeoPixel strips).

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT  60

// NeoPixel brightness, 0 (min) to 255 (max)
#define BRIGHTNESS 50 // Set BRIGHTNESS to about 1/5 (max = 255)


// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  strip1.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip1.show();            // Turn OFF all pixels ASAP
  strip1.setBrightness(BRIGHTNESS);
  
  strip2.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip2.show();            // Turn OFF all pixels ASAP
  strip2.setBrightness(BRIGHTNESS);

  strip3.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip3.show();            // Turn OFF all pixels ASAP
  strip3.setBrightness(BRIGHTNESS + BRIGHTNESS);

  strip4.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip4.show();            // Turn OFF all pixels ASAP
  strip4.setBrightness(BRIGHTNESS + BRIGHTNESS);
}

void loop() {
  
  // strip1
  colorWipe(&strip1, strip1.Color(255,   0,   0)     , 50); // Red
  colorWipe(&strip1, strip1.Color(  0, 255,   0)     , 50); // Green
  // colorWipe(&strip1, strip1.Color(  0,   0, 255)     , 50); // Blue
  // colorWipe(&strip1, strip1.Color(  0,   0,   0, 255), 50); // True white (not RGB white)
  // whiteOverRainbow(&strip1, 75, 5);
  // pulseWhite(&strip1, 5);
  // rainbowFade2White(&strip1, 3, 3, 1);


  // strip2
  colorWipe(&strip2, strip2.Color(255,   0,   0)     , 50); // Red
  colorWipe(&strip2, strip2.Color(  0, 255,   0)     , 50); // Green
  // colorWipe(&strip2, strip2.Color(  0,   0, 255)     , 50); // Blue
  // colorWipe(&strip2, strip2.Color(  0,   0,   0, 255), 50); // True white (not RGB white)
  // whiteOverRainbow(&strip2, 75, 5);
  // pulseWhite(&strip2, 5);
  rainbowFade2White(&strip2, 3, 3, 1);

  // strip3
  colorWipe(&strip3, strip3.Color(255,   0,   0)     , 50); // Red
  colorWipe(&strip3, strip3.Color(  0, 255,   0)     , 50); // Green
  // colorWipe(&strip3, strip3.Color(  0,   0, 255)     , 50); // Blue
  // colorWipe(&strip3, strip3.Color(  0,   0,   0, 255), 50); // True white (not RGB white)
  // whiteOverRainbow(&strip3, 75, 5);
  // pulseWhite(&strip3, 5);
  //rainbowFade2White(&strip3, 3, 3, 1);

  // strip4
  colorWipe(&strip4, strip4.Color(255,   0,   0)     , 50); // Red
  colorWipe(&strip4, strip4.Color(  0, 255,   0)     , 50); // Green
  // colorWipe(&strip4, strip4.Color(  0,   0, 255)     , 50); // Blue
  // colorWipe(&strip4, strip4.Color(  0,   0,   0, 255), 50); // True white (not RGB white)
  // whiteOverRainbow(&strip4, 75, 5);
  pulseWhite(&strip4, 5);
  //rainbowFade2White(&strip4, 3, 3, 1);
}

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(Adafruit_NeoPixel *strip, uint32_t color, int wait) {
  for(int i=0; i<strip->numPixels(); i++) { // For each pixel in strip...
    strip->setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip->show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void whiteOverRainbow(Adafruit_NeoPixel *strip, int whiteSpeed, int whiteLength) {

  if(whiteLength >= strip->numPixels()) whiteLength = strip->numPixels() - 1;

  int      head          = whiteLength - 1;
  int      tail          = 0;
  int      loops         = 3;
  int      loopNum       = 0;
  uint32_t lastTime      = millis();
  uint32_t firstPixelHue = 0;

  for(;;) { // Repeat forever (or until a 'break' or 'return')
    for(int i=0; i<strip->numPixels(); i++) {  // For each pixel in strip...
      if(((i >= tail) && (i <= head)) ||      //  If between head & tail...
         ((tail > head) && ((i >= tail) || (i <= head)))) {
        strip->setPixelColor(i, strip->Color(0, 0, 0, 255)); // Set white
      } else {                                             // else set rainbow
        int pixelHue = firstPixelHue + (i * 65536L / strip->numPixels());
        strip->setPixelColor(i, strip->gamma32(strip->ColorHSV(pixelHue)));
      }
    }

    strip->show(); // Update strip with new contents
    // There's no delay here, it just runs full-tilt until the timer and
    // counter combination below runs out.

    firstPixelHue += 40; // Advance just a little along the color wheel

    if((millis() - lastTime) > whiteSpeed) { // Time to update head/tail?
      if(++head >= strip->numPixels()) {      // Advance head, wrap around
        head = 0;
        if(++loopNum >= loops) return;
      }
      if(++tail >= strip->numPixels()) {      // Advance tail, wrap around
        tail = 0;
      }
      lastTime = millis();                   // Save time of last movement
    }
  }
}

void pulseWhite(Adafruit_NeoPixel *strip, uint8_t wait) {
  for(int j=0; j<256; j++) { // Ramp up from 0 to 255
    // Fill entire strip with white at gamma-corrected brightness level 'j':
    strip->fill(strip->Color(0, 0, 0, strip->gamma8(j)));
    strip->show();
    delay(wait);
  }

  for(int j=255; j>=0; j--) { // Ramp down from 255 to 0
    strip->fill(strip->Color(0, 0, 0, strip->gamma8(j)));
    strip->show();
    delay(wait);
  }
}

void rainbowFade2White(Adafruit_NeoPixel *strip, int wait, int rainbowLoops, int whiteLoops) {
  int fadeVal=0, fadeMax=100;

  // Hue of first pixel runs 'rainbowLoops' complete loops through the color
  // wheel. Color wheel has a range of 65536 but it's OK if we roll over, so
  // just count from 0 to rainbowLoops*65536, using steps of 256 so we
  // advance around the wheel at a decent clip.
  for(uint32_t firstPixelHue = 0; firstPixelHue < rainbowLoops*65536;
    firstPixelHue += 256) {

    for(int i=0; i<strip->numPixels(); i++) { // For each pixel in strip...

      // Offset pixel hue by an amount to make one full revolution of the
      // color wheel (range of 65536) along the length of the strip
      // (strip.numPixels() steps):
      uint32_t pixelHue = firstPixelHue + (i * 65536L / strip->numPixels());

      // strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
      // optionally add saturation and value (brightness) (each 0 to 255).
      // Here we're using just the three-argument variant, though the
      // second value (saturation) is a constant 255.
      strip->setPixelColor(i, strip->gamma32(strip->ColorHSV(pixelHue, 255,
        255 * fadeVal / fadeMax)));
    }

    strip->show();
    delay(wait);

    if(firstPixelHue < 65536) {                              // First loop,
      if(fadeVal < fadeMax) fadeVal++;                       // fade in
    } else if(firstPixelHue >= ((rainbowLoops-1) * 65536)) { // Last loop,
      if(fadeVal > 0) fadeVal--;                             // fade out
    } else {
      fadeVal = fadeMax; // Interim loop, make sure fade is at max
    }
  }

  for(int k=0; k<whiteLoops; k++) {
    for(int j=0; j<256; j++) { // Ramp up 0 to 255
      // Fill entire strip with white at gamma-corrected brightness level 'j':
      strip->fill(strip->Color(0, 0, 0, strip->gamma8(j)));
      strip->show();
    }
    delay(1000); // Pause 1 second
    for(int j=255; j>=0; j--) { // Ramp down 255 to 0
      strip->fill(strip->Color(0, 0, 0, strip->gamma8(j)));
      strip->show();
    }
  }

  delay(500); // Pause 1/2 second
}