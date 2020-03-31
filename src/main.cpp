#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS    144 
#define DATA_PIN    28
#define CLOCK_PIN   27
#define COLOR_ORDER BGR
#define BRIGHTNESS  3
#define FRAMES_PER_SECOND  120
CRGB leds[NUM_LEDS];


void setup() 
{
  delay(5000); // 3 second delay for recovery
  FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.println("Start up Finished");
}

void loop() 
{
  
}