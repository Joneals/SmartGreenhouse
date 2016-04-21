#include <SparkFunHTU21D.h>
#include <LiquidCrystal.h>
#include <Wire.h>

LiquidCrystal lcd(12,11,5,4,3,2);

HTU21D hSensor;

const int temperaturePin = A0;
int bulbPin;
int fanPin1;

int tempMin;
int tempMax;
int tempIdeal;


void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  hSensor.begin();
}

float humd;
float voltage, degreesC, degreesF;
float humidity = 50.0;
int state;

void loop()
{
  lcd.setCursor(0,0);
  //** Read temperature sensors, perform necessary conversions **// 
  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;

  //Read humidity information from sensors, do necessary conversions
    //*****TODO*******//
    if (random(1,10)>8)
      humidity += random(-1,2); //Test code since the sensor is 

    //float humidity = hSensor.readHumidity();
   // float degreesC = hSensor.readTemperature();

  // Logic to determine what temperature state we are in, what action needs to be taken
  if (degreesC > tempIdeal)
    //disable heat
  if (degreesC < tempIdeal)
    //disable fan
  if (degreesC < tempMin)
    //enable heater
  if (degreesC > tempMax)
    //enable fan

  //** Print live data to the LCD screen **//
  lcd.print(" ");//For some reason this statement is ignored?
  lcd.print("Temp: ");
  lcd.print(degreesC);
  lcd.write(223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(round(humd));
  lcd.print("%");

  //Print humidity info
  
  delay(10000); //Delay should be longer in release version, 
   
}

float getVoltage(int pin)
{  
  return (analogRead(pin) * 0.004882814); 
}


