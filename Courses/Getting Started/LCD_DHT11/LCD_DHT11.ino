#include <LiquidCrystal.h>
#include <DHT.h>

#define RSpin 6
#define ENABLEpin 7
#define D4pin 10
#define D5pin 11
#define D6pin 12
#define D7pin 13

#define DHT11pin 2
#define DHT11type DHT11

DHT dht(DHT11pin, DHT11type);

//LiquidCrystal(rs, enable, d4, d5, d6, d7) 
//LiquidCrystal(rs, rw, enable, d4, d5, d6, d7) 
//LiquidCrystal(rs, enable, d0, d1, d2, d3, d4, d5, d6, d7) 
//LiquidCrystal(rs, rw, enable, d0, d1, d2, d3, d4, d5, d6, d7)

//FUNCTIONS
//begin(cols, rows) - initializes the interface of the LCD screen and specifies the dimensions of the display
//clear() - clears the LCD screen and positions the cursor in the upper-left corner
//home() - positions the cursor in the upper-left corner
//setCursor(col, row) - positions the LCD cursor at the specified col and row for subsequent text (0 being the first col/row)
//write(data) - writes a character to the LCD
//print(data, BASE-optional) - prints text to the LCD. BASE in which to print the numbers (BIN, DEC, OCT, HEX)

LiquidCrystal lcd(RSpin, ENABLEpin, D4pin, D5pin, D6pin, D7pin);

void setup() {
  
  lcd.begin(16, 2);       //set up the LCD's number of columns and rows
  lcd.print("DHT Test");  //print a message to the LCD
  dht.begin();            //initializes DHT
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h))
  {
    lcd.clear();
    lcd.home();
    lcd.print("Can't get reading");
    lcd.setCursor(0,1);
    lcd.print("from DHT");
  }
  else
  {
    lcd.clear();
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.print(" %");
    lcd.setCursor(0,1);
    lcd.print("Temp: ");
    lcd.print(t);
    lcd.print(" degC");
  }

  delay(5000);

}
