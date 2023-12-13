#include <OctoWS2811.h>
#define LED_STRIP_COUNT       6    // 6
#define RAINBOW_COLORS        100 // 180
#define CYCLE_TIME_IN_MS      10000 // 18000 // 1000
#define BRIGHTNESS_CYCLE_TIME_IN_MS     5000 // 1000 , unused
#define DEFAULT_BRIGHTNESS              50
#define DEFAULT_SATURATION              200
const int ledsPerStrip = 144;
int cur_lightness = DEFAULT_BRIGHTNESS;
DMAMEM int displayMemory[ledsPerStrip*LED_STRIP_COUNT];
int drawingMemory[ledsPerStrip*LED_STRIP_COUNT];

const int config = WS2811_GRB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

int rainbowColors[RAINBOW_COLORS];


void setup() {
  pinMode(1, OUTPUT);
  digitalWrite(1, HIGH);
  for (int i=0; i<RAINBOW_COLORS; i++) {
    int hue = i * 2;
    int saturation = DEFAULT_SATURATION;
    cur_lightness = DEFAULT_BRIGHTNESS;
    // pre-compute the 180 rainbow colors
    rainbowColors[i] = makeColor(hue, saturation, cur_lightness);
  }
  digitalWrite(1, LOW);
  leds.begin();
}


void loop() {
  rainbow(10, 2500);
}

// phaseShift is the shift between each row.  phaseShift=0
// causes all rows to show the same colors moving together.
// phaseShift=180 causes each row to be the opposite colors
// as the previous.
//
// cycleTime is the number of milliseconds to shift through
// the entire 360 degrees of the color wheel:
// Red -> Orange -> Yellow -> Green -> Blue -> Violet -> Red
//
void rainbow(int phaseShift, int cycleTime)
{
  int color, x, y, wait;

  wait = cycleTime * CYCLE_TIME_IN_MS / ledsPerStrip;
  for (color=0; color < 180; color++) {
    digitalWrite(1, HIGH);
    for (x=0; x < ledsPerStrip; x++) {
      for (y=0; y < 8; y++) {
        int index = (color + x + y*phaseShift/2) % 180;
        leds.setPixel(x + y*ledsPerStrip, rainbowColors[index]);
      }
    }
    leds.show();
    digitalWrite(1, LOW);
    delayMicroseconds(wait);
  }
}
