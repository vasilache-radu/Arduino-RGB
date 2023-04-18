#include <FastLED.h>


#define NUM_LEDS 16

const int ledPin=5;
CRGB leds[NUM_LEDS];

int rval;
int gval;
int bval;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode (ledPin, OUTPUT);
    FastLED.addLeds<WS2812B, ledPin, GRB>(leds, NUM_LEDS);
}

void loop() {
  // put your main code here, to run repeatedly:

  while(Serial.available()==0){
    Serial.print("Waiting for a command");
  }
  
    char command = '0';

    command = Serial.read();

    if(command = 'l'){
      while(Serial.available()==0){
        Serial.print("Waiting for a command");
      }

      int value[3] ={0};
      for(int i=0; i<3 && Serial.available()>0; i++){

        value[i]= Serial. parseInt();
      }

      for(int i=0; i<NUM_LEDS; i++)
        leds[i] = CRGB (value[0], value[1], value[2]);
      
      FastLED.show();
      
    }
    if(command == 'p'){

    }
    if(command == 'f'){

    }
  

}
