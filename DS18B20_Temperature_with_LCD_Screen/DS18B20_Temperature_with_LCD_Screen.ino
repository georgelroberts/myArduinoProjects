#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
// Data wire is plugged into port 6 on the Arduino
#define ONE_WIRE_BUS 6
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  lcd.begin(16,2);
}
void loop(void)
{
  float tempAv=0;
  float humidAv=0;
  int noLoops=10;
  
  for(int i=0;i<noLoops;i++){
    sensors.requestTemperatures(); // Send the command to get temperatures
    tempAv+=sensors.getTempCByIndex(0);
    delay(750);
  }
  tempAv=tempAv/noLoops;
  Serial.print(millis());
  Serial.print("\t");
  Serial.println(tempAv);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempAv);
  lcd.print("*C");
}

