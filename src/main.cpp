#include <Arduino.h>
#include <FastLED.h>
//***********Constants*****************
#define NUM_LEDS 144
#define DATA_PIN 34
#define CLOCK_PIN 33
#define COLOR_ORDER BGR
#define BRIGHTNESS 3
#define FRAMES_PER_SECOND 120
const long period = 100;                       //delay between increments

//*************Variables*************
CRGB leds[NUM_LEDS];
long startMillis = 0;
int x = 0;
/**************Function***************
Purpose:
Provides ability to send multiple led pulses down strip simultaneously.
Based on "LedChasingFullySolved191015c"
Parameters: 
NA
*************************************/
void NextPulse()
{
  for (int c = NUM_LEDS - 1; c >= 1; c--)
  {
    leds[c] = leds[c - 1];
  }
  leds[0] = CRGB::Black;
  FastLED.show();
}
//**************Set Up****************
void setup()
{
  delay(5000); // 3 second delay for recovery
  FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.println("Start up Finished");
}
//*************Loop*******************
void loop()
{
  unsigned long currentMillis = millis();      // Note the time
  if (Serial.available() > 0)                  // Check for inputs from the serial line
  {
    byte inByte = Serial.read();               // Read the input character
    switch (inByte)
    {
      case 'a':                               // Start a new pulse train
        Serial.println("a");                   // echo the input
        leds[x] = CRGB::Blue;
        break;
      case 'b':
        Serial.println("b");
        leds[x+1] = CRGB::OrangeRed;
        break;
      case 'c':
        Serial.println("c");
        leds[x+2] = CRGB::Gold;
        break;
      case 'd':
        Serial.println("d");
        leds[x+3] = CRGB::DarkViolet;
        break;
       case 'e':
        Serial.println("e");
        leds[x+4] = CRGB::Red;
        break;

        case 'f':
        Serial.println("f");
        leds[x+5] = CRGB::Green;
        break;
      default:;
    }//switch
  }//if
  if (currentMillis - startMillis >= period)
  {
    startMillis = currentMillis;                  // reset the start time for the next period
    NextPulse();                                   //move led down the strip
  }
}//loop