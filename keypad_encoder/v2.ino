/*
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Define the pins for the keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};
byte rowPins[ROWS] = {4, 5, 6, 7};
byte colPins[COLS] = {8, 9, 10, 11};
  // Connect to the column pinouts of the keypad

// Initialize the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Define the pins for the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address, cols, rows

// Define the target RPM
int targetRPM = 1000;

void setup()
{
  // Initialize the LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Target RPM: ");
  lcd.setCursor(0, 1);
  lcd.print(targetRPM);
}

void loop()
{
  // Check for keypad input
  char key = keypad.getKey();
  if (key)
  {
    switch (key)
    {
    case 'A':
      // Increase target RPM by 100
      targetRPM += 100;
      break;
    case 'B':
      // Decrease target RPM by 100
      targetRPM -= 100;
      break;
    case 'C':
      // Increase target RPM by 10
      targetRPM += 10;
      break;
    case 'D':
      // Decrease target RPM by 10
      targetRPM -= 10;
      break;
    }
    // Update LCD with new target RPM
    lcd.setCursor(0, 1);
    lcd.print("       ");
    lcd.setCursor(0, 1);
    lcd.print(targetRPM);
  }
  delay(100);
}
*/