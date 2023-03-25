/*#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[ROWS] = {4, 5, 6, 7};
byte colPins[COLS] = {8, 9, 10, 11};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int hallPin = 2;
const int interruptPin = 0;

volatile int rpm = 0;

void isr()
{
  rpm++;
}

void setup()
{
  lcd.init();
  lcd.backlight();

  pinMode(hallPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), isr, RISING);
}

void loop()
{
  char key = keypad.getKey();

  if (key == 'A')
  {
    rpm = 0;
  }

  int rpmValue = rpm * 60 / 7.5;

  lcd.setCursor(0, 0);
  lcd.print("RPM: ");
  lcd.print(rpmValue);

  delay(500);
}
*/
