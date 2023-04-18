// include the library code:
#include <LiquidCrystal.h>
#include <dht.h>

dht DHT;

#define DHT11_PIN 7


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("Team SUV");
  lcd.setCursor(0,0);
  lcd.print("Temperature = ");
  lcd.setCursor(0,1);
  lcd.print("Humidity = ");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  int chk = DHT.read11(DHT11_PIN);
  //Serial.print("Temperature = ");  
  lcd.setCursor(14, 0);
  lcd.print(DHT.temperature);
  //Serial.print("Humidity = ");
  lcd.setCursor(11, 1);
  lcd.println(DHT.humidity);
  delay(1000);
  
  
}