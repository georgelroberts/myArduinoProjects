#include <SimpleDHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

//www.elegoo.com
//2016.06.13

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND

int pinDHT11 = 6;
SimpleDHT11 dht11;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // start working...
  float tempAv=0;
  float humidAv=0;
  int noLoops=10;
  
  for(int i=0;i<noLoops;i++){
    // read with raw sample data.
    byte temperature = 0;
    byte humidity = 0;
    byte data[40] = {0};
    if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
      //Serial.print("Read DHT11 failed");
      return;
    }
    tempAv+=temperature;
    humidAv+=humidity;
    
    // DHT11 sampling rate is 1HZ.
    delay(1000);
  }

  humidAv=humidAv/noLoops;
  tempAv=tempAv/noLoops;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(tempAv);
  lcd.print("*C");
  Serial.print("&T\t");
  Serial.print(tempAv);
  Serial.print("\t");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidAv);
  lcd.print("%");
  Serial.println(humidAv);

  
  
}
