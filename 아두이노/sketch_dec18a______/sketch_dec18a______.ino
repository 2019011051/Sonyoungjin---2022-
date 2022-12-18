#include <Adafruit_NeoPixel.h>  //Loading Library Files to Implement NeoPixels

#define PIN 2   // input pin Neopixel is attached to

#define NUMPIXELS      40 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//Setting Variables
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int value = 0;
int sensorpin = 13;
int pirstate = LOW;
int delayval = 10; // timing delay in milliseconds


void setup() 
{
  
  pinMode(sensorpin, INPUT);  //PIR sensor pin to INPUT
  Serial.begin(9600);
  pixels.begin();  // Initialize the NeoPixel library.
}

void loop() 
{
  int cds = analogRead(A0);    //Connect the illumination sensor to the analogRead (A0)
  
  setColor();                  //Call up color functions to enter neo fixel
  
  value = digitalRead(sensorpin);     
 
  
  if(cds>500 && value==HIGH)        //If the illumination sensor receives a high value by detecting light and movement of 500 or more,
  {
    
    for (int i=0; i < NUMPIXELS; i++)   //If the light sensor recognizes darkness and the PIR sensor detects movement,
    {
     pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); // pixels.Color taks RGB values, from 0,0,0 up to 255,255,255
     pixels.show(); // This sends the updated pixel color to the hardware
     delay(delayval); // Delay for a period of time (in milliseconds).
     
      if (pirstate==LOW)
      {
        Serial.println("Car motion has been detected.");
        pirstate == HIGH;
      }

    }
  }
  else
  {
    for(int i=0; i< NUMPIXELS; i++)
    {
      pixels.setPixelColor(i, pixels.Color(0,0,0));  //If the above conditions are not met, add 0,0,0 to the led RGB to prevent light from coming out
      pixels.show();
    }
    
    delay(delayval);
  }
  
}



void setColor() // setcolor function, Select any value to set for RGB
{
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
