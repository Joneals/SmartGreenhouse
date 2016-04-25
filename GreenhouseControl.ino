#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);


int pinTemperature = A0;
int pinPhotocell = A1;
int pinBulb;
int pinFan;
int pinLED;
int darkvalue;


int tempMin;
int tempMax;
int tempIdeal;


void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
}

float voltage, degreesC, degreesF;
int bulb, fan, led;

void loop()
{
  lcd.setCursor(0,0);
  //** Read temperature sensors, perform necessary conversions **// 
  voltage = getVoltage(pinTemperature);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;

  // Read light values
  int darkness = analogRead(pinPhotocell);

  // Logic to determine what temperature state we are in, what action needs to be taken
  if (degreesC > tempIdeal)
    bulb = LOW;
  if (degreesC < tempIdeal)
    fan = LOW;
  if (degreesC < tempMin)
    bulb = HIGH;
  if (degreesC > tempMax)
   fan = HIGH;

  if (darkness > darkvalue)
    led = HIGH;

   digitalWrite(pinFan, fan);
   digitalWrite(pinBulb, bulb);
   digitalWrite(pinLED, led);
   

  //** Print live data to the LCD screen **//
  lcd.print(" ");//For some reason this statement is ignored?
  lcd.print("Temp: ");
  lcd.print(degreesC);
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(0,1);

  //Print humidity info
  
  delay(10000); //Delay should be longer in release version, 
   
}

float getVoltage(int pin)
{  
  return (analogRead(pin) * 0.004882814); 
}




