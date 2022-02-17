#include <Arduino.h>


/*
  Simple Blink sketch
  simple-blink.cpp
  Use for PlatformIO demo

  From original Arduino Blink Sketch
  https://www.arduino.cc/en/Tutorial/Blink
  
  DroneBot Workshop 2021
  https://dronebotworkshop.com
*/

// Set LED_BUILTIN if undefined or not pin 13
// #define LED_BUILTIN 13

int INPIN = 2;    // pushbutton connected to digital pin 7
int INPIN2 = 7;  
unsigned long myTime;
unsigned long leftTime;
unsigned long rightTime;
bool leftTriggered = false;
bool rightTriggered = false;
bool leftFirst = false;
bool rightFirst = false;

void setup()
{
  pinMode(INPIN, INPUT);    // sets the digital pin 7 as input
  pinMode(INPIN2, INPUT);    // sets the digital pin 7 as input

  Serial.begin(9600);
  myTime = millis();
}

void loop()
{
  // Set the LED HIGH
  if(digitalRead(INPIN) == HIGH){
    leftTriggered = true;
  }

  if(digitalRead(INPIN2) == HIGH){
    rightTriggered = true;
  }

    if (leftTriggered && !rightTriggered){
      leftFirst = true;
    }
    else if(rightTriggered && !leftTriggered){
      rightFirst = true;
    }


    if (leftTriggered){
      if (rightFirst){
        Serial.println("right triggered first");
        delay(100);
      }
    }
    
    if (rightTriggered){
      if (leftFirst){
       Serial.println("left triggered first");
        delay(100);
      }
    }
    

  if (millis() > myTime + 100){
    leftTriggered = false;
    rightTriggered = false;
    leftFirst = false;
    rightFirst = false;
    myTime = millis();
  }
}