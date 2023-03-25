#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set I2C address ke 0x27

void setup() 
{
  lcd.init();                      // inisialisasi LCD
  lcd.backlight();                 // nyalakan backlight
}

void loop() 
{
  lcd.clear();
  lcd.print("mRobot.Store");       // tampilkan tulisan
  delay(50);
}
