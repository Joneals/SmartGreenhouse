

#include <LiquidCrystal.h>
#include <Wire.h>
#include "SparkFunHTU21D.h"

LiquidCrystal lcd(12,11,5,4,3,2);

const int temperaturePin = A0;
const int bulbPin;
const int fanPin1;

int tempMin;
int tempMax;
int tempIdeal;


void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

float humd;
float voltage, degreesC, degreesF;

void loop()
{
  lcd.setCursor(0,0);
  //** Read temperature sensors, perform necessary conversions **// 
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;

  //Read humidity information from sensors, do necessary conversions
    //*****TODO*******//

  if (degreesC > tempIdeal)
    //disable heat
  if (degreesC < tempIdeal)
    //disable cooling
  if (degreesC < tempMin)
    //enable heat 
  if (degreesC > tempMax)
    //enable cooling


  //** Print live data to the LCD screen **//
  lcd.print("Degrees F: ");
  lcd.print(degreesF);

  //Print humidity info
  
  delay(1000); //Delay should be longer in release version, 
   
}


float getVoltage(int pin)
{  
  return (analogRead(pin) * 0.004882814); 
}


