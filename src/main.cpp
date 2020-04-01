#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS    144 
#define DATA_PIN    34
#define CLOCK_PIN   33
#define COLOR_ORDER BGR
#define BRIGHTNESS  3
#define FRAMES_PER_SECOND  120
CRGB leds[NUM_LEDS];

/************************************
Purpose:
Gradually Fades LEDs after they turn on

Parameters: 
NA
The lower the .nscale argument, the faster the LEDs turn off (i.e. shorter the trail is.
*****/
void fadeall() 
{ 
  for(int i = 0; i < NUM_LEDS; i++) 
    { 
    leds[i].nscale8(120); 
    } 
}

void setup() 
{
  delay(5000); // 3 second delay for recovery
  FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.println("Start up Finished");
}

void loop() 
{
   for (int x = 0; x <144; x++) //moves LEDs forward
    {
      leds[x] = CHSV(255, 255, 255);
      FastLED.show();
      fadeall();
      delay(25);
    } 
}