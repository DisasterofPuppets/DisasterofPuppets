/*
Disaster of Puppets is owning up to writing this trash
I'm sure it can be done a lot easier but eh, it works.
Twitch.tv/disasterofpuppets
*/

#include <FastLED.h>

#define LED_PIN 12
#define NUM_LEDS 3
#define COLOR_ORDER GRB
#define COOLING 55
#define SPARKING 120
#define BRIGHTNESS 50

CRGB leds[NUM_LEDS];

const int rPin = 2;
const int pPin = 4;
const int sPin = 6;

int rockState;
int paperState;
int scissorState;
int randomPlay;
uint8_t gHue = 0; // rotating "base color" used by many of the patterns

String Choice, Blank, Result, Rock, Paper, Scissors;

bool gReverseDirection = false;
bool awaitingPress = true;

void setup() 

{

FastLED.addLeds<WS2812, LED_PIN, COLOR_ORDER>(leds,NUM_LEDS).setCorrection( TypicalLEDStrip );
FastLED.setBrightness(BRIGHTNESS);

    randomSeed(200);    
    pinMode(rPin,INPUT_PULLUP);
    pinMode(pPin,INPUT_PULLUP);
    pinMode(sPin,INPUT_PULLUP);
    Serial.begin(9600);

Choice = String("Pending");
Blank = String("Pending");
Rock = String("Rock");
Paper = String("Paper");
Scissors = String("Scissors");
}


void loop() 
  {
   
    rockState = digitalRead(rPin);
    paperState = digitalRead(pPin);
    scissorState = digitalRead(sPin);

      leds[0] = CRGB::Green;
      leds[1] = CRGB::Green;
      leds[2] = CRGB::Green;
    FastLED.show();

awaitingPress = true;
while (awaitingPress)
  {
  if (rockState or paperState or scissorState)
    {
            awaitingPress = false;
    }
  else if (Choice == Blank)
      {
        leds[0] = CRGB(0,255,0);
        leds[1] = CRGB(0,255,0);
        leds[2] = CRGB(0,255,0);
        FastLED.show();
      }
    }
 
if (rockState == 0)
    {
        Choice = String("Rock");
        FastLED.clear();
        leds[0] = 0x07E0;
    }
        else if (paperState == 0)
              {
                  Choice = String("Paper");
                  FastLED.clear();
                  leds[1] = 0x07E0;
              }
                  else if (scissorState == 0)
                        {
                            Choice = String("Scissors");
                            FastLED.clear();
                            leds[2] = 0x07E0;
                        }
                            FastLED.show();     
                            delay(500);
    
      //Randomly select PC selection of Rock, Paper, Scissors

randomPlay = random(0,3);

if (randomPlay == 0)
      {
        Result = String("Rock");
      }
            else if (randomPlay == 1)
               {
                  Result = String("Paper");
               }
               else if (randomPlay == 2)
                  {
                    Result = String("Scissors");
                  }
  
      
// compare

// DRAW-----------------------------

if (Choice == Result)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.println(" and so did I ");
      Serial.println("IT'S A DRAW");
      leds[0] = CRGB::Yellow;
      leds[1] = CRGB::Yellow;
      leds[2] = CRGB::Yellow;
      FastLED.show();
      // PAUSE UNTIL BUTTON PUSHED AGAIN
      delay(1000);
      FastLED.clear();
    }

// ROCK BEAT SCISSORS---------------

if (Choice == Rock && Result == Scissors)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.print(" and I chose ");
      Serial.println(Result);
      Serial.println("YOU WIN, YOU ARE GOOD AT THIS");
      Flash();
      delay(1000);
      // PAUSE UNTIL BUTTON PUSHED AGAIN
      FastLED.clear();
    }

// ROCK BEATEN BY PAPER----------    

if (Choice == Rock && Result == Paper)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.print(" and I chose ");
      Serial.println(Result);
      Serial.println("YOU LOOSE");
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Red;
      FastLED.show();
      // PAUSE UNTIL BUTTON PUSHED AGAIN
      delay(1000);
      FastLED.clear();
    }

// SCISSORS BEAT PAPER---------------

if (Choice == Scissors && Result == Paper)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.print(" and I chose ");
      Serial.println(Result);
      Serial.println("YOU WIN, YOU GOT LUCKY");
      Flash();
      delay(1000); 
      // PAUSE UNTIL BUTTON PUSHED AGAIN
      
      FastLED.clear();

    }

// SCISSORS BEATEN BY ROCK----------    

if (Choice == Scissors && Result == Rock)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.print(" and I chose ");
      Serial.println(Result);
      Serial.println("YOU LOOSE, BETTER LUCK NEXT TIME");
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Red;
      FastLED.show();
      delay(1000);
      FastLED.clear();
    }

 // PAPER BEATS ROCK---------------

if (Choice == Paper && Result == Rock)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.print(" and I chose ");
      Serial.println(Result);
      Serial.println("YOU WIN, ARE YOU CHEATING?");
      Flash();
      delay(1000);
      FastLED.clear();
    }

// PAPER BEATEN BY SCISSORS----------    

if (Choice == Paper && Result == Scissors)

    {
      Serial.print("You chose ");
      Serial.print(Choice);
      Serial.print(" and I chose ");
      Serial.println(Result);
      Serial.println("YOU LOOSE, BETTER LUCK NEXT TIME");
      leds[0] = CRGB::Red;
      leds[1] = CRGB::Red;
      leds[2] = CRGB::Red;
      FastLED.show();
      delay(1000);
      FastLED.clear();
    }


Choice = String("Pending");
Result = String("");
 
}



void Flash()
{
   leds[0] = CRGB::Blue;
   leds[1] = CRGB::Blue;
   leds[2] = CRGB::Blue;
   FastLED.show();
   delay(100);
   leds[0] = CRGB::Magenta;
   leds[1] = CRGB::Magenta;
   leds[2] = CRGB::Magenta;
   FastLED.show();
   delay(100);
   leds[0] = CRGB::Teal;
   leds[1] = CRGB::Teal;
   leds[2] = CRGB::Teal;
   FastLED.show();
   delay(100);
   leds[0] = CRGB::Pink;
   leds[1] = CRGB::Pink;
   leds[2] = CRGB::Pink;
   delay(100);
     leds[0] = CRGB::Blue;
   leds[1] = CRGB::Blue;
   leds[2] = CRGB::Blue;
   FastLED.show();
   delay(100);
   leds[0] = CRGB::Magenta;
   leds[1] = CRGB::Magenta;
   leds[2] = CRGB::Magenta;
   FastLED.show();
   delay(100);
   leds[0] = CRGB::Teal;
   leds[1] = CRGB::Teal;
   leds[2] = CRGB::Teal;
   FastLED.show();
   delay(100);
   leds[0] = CRGB::Pink;
   leds[1] = CRGB::Pink;
   leds[2] = CRGB::Pink;
   delay(100);
   leds[0] = CRGB::Blue;
   leds[1] = CRGB::Blue;
   leds[2] = CRGB::Blue;
   FastLED.show();
 
}
