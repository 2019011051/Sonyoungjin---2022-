#include<Servo.h>

Servo servo;

int value =0;
int redpin = 5;
int greenpin = 4;
int bluepin = 3;
int yellowpin = 2;

int Delay = 50;

void setup()
{
   servo.attach(7);
  
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
    
    if(input == '1')
    {
      value += 30;
      
      if(value == 180)
        value=0;
    }
      else
      {
        value = 0;
      }
    
    servo.write(value);
    
    if(value ==30)
    {
      digitalWrite(redpin, HIGH);
      Serial.print("RedLED : on\n");
      delay(readValue);
      digitalWrite(redpin, LOW);
      Serial.print("RedLED : off\n");
      delay(readValue);
      
      digitalWrite(greenpin, HIGH);
      Serial.print("greenLED : on\n");
      delay(readValue);
      digitalWrite(greenpin, LOW);
      Serial.print("greenLED : off\n");
      delay(readValue);
    }
    
    if(value ==60)
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
    
    if(value == 90)
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
    
    if(value== 120)
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
    
    if(value == 150)
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
