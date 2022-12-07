#include<Servo.h>

//Servomotor use
Servo servo;

//Variable declaration
int value =0;
int redpin = 5;
int greenpin = 4;
int bluepin = 3;
int yellowpin = 2;

int Delay = 50;

void setup()
{
   servo.attach(7);     //Servomotor is number 7
  
  pinMode(redpin, OUTPUT);  
  pinMode(greenpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int readValue = analogRead(A0);
  
  if(Serial.available())
  {
    char input; 
    input = Serial.read();
    
    if(input == '1')   //1 input
    {
      value += 30;     //It rotates by 30 degrees
      
      if(value == 180)  //Initialize to zero if you fill 180 degrees
        value=0;
    }
      else
      {
        value = 0;      
      }
    
    servo.write(value);
    
    if(value ==30)         // If the angle is 30,
    {
      digitalWrite(redpin, HIGH);    
      Serial.print("RedLED : on\n");
      delay(readValue);  // Wait for 500 millisecond(s)
      digitalWrite(redpin, LOW);
      Serial.print("RedLED : off\n");
      delay(readValue);    // Wait for 1000 millisecond(s)
      
      digitalWrite(greenpin, HIGH);
      Serial.print("greenLED : on\n");
      delay(readValue);
      digitalWrite(greenpin, LOW);
      Serial.print("greenLED : off\n");
      delay(readValue);
    }
    
    if(value ==60)       // // If the angle is 60
    {
      
      digitalWrite(bluepin, HIGH);
      Serial.print("blueLED : on\n");
      delay(readValue);
      digitalWrite(bluepin, LOW);
      Serial.print("blueLED : off\n");
      delay(readValue);
      
      digitalWrite(yellowpin, HIGH);
      Serial.print("yellowLED : on\n");
      delay(readValue);
      digitalWrite(yellowpin, LOW);
      Serial.print("yellowLED : off\n");
      delay(readValue);
    }
    
    if(value == 90)           // // If the angle is 90
    {
      digitalWrite(redpin, HIGH);
      Serial.print("RedLED : on\n");
      delay(readValue);
      digitalWrite(redpin, LOW);
      Serial.print("RedLED : off\n");
      delay(readValue);
      
      digitalWrite(bluepin, HIGH);
      Serial.print("blueLED : on\n");
      delay(readValue);
      digitalWrite(bluepin, LOW);
      Serial.print("blueLED : off\n");
      delay(readValue);
    }
    
    if(value== 120)          // // If the angle is 120
    {
      digitalWrite(greenpin, HIGH);
      Serial.print("greenLED : on\n");
      delay(readValue);
      digitalWrite(greenpin, LOW);
      Serial.print("greenLED : off\n");
      delay(readValue);
      
      digitalWrite(yellowpin, HIGH);
      Serial.print("yellowLED : on\n");
      delay(readValue);
      digitalWrite(yellowpin, LOW);
      Serial.print("yellowLED : off\n");
      delay(readValue);
    }
    
    if(value == 150)          // // If the angle is 150
    {
      
      digitalWrite(greenpin, HIGH);
      Serial.print("greenLED : on\n");
      delay(readValue);
      digitalWrite(greenpin, LOW);
      Serial.print("greenLED : off\n");
      delay(readValue);
       
     
      digitalWrite(bluepin, HIGH);
      Serial.print("blueLED : on\n");
      delay(readValue);
      digitalWrite(bluepin, LOW);
      Serial.print("blueLED : off\n");
      delay(readValue);
    }
 }
}
