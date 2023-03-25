#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {4, 5, 6, 7};
byte colPins[COLS] = {8, 9, 10, 11};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int poin = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Poin: ");
}

void loop() {
  char key = keypad.getKey();

  if (key == 'A') {
    // Masuk ke sub-menu set poin
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Set Poin: ");
    lcd.setCursor(0, 1);
    lcd.print(poin);
    while (1) {
      char subKey = keypad.getKey();
      if (subKey) {
        if (subKey == 'A') {
          // Kembali ke menu utama
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Poin: ");
          lcd.setCursor(0, 1);
          lcd.print(poin);
          break;
        }
        else if (subKey == '#') {
          // Menyimpan nilai poin
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Poin: ");
          lcd.setCursor(0, 1);
          lcd.print(poin);
          break;
        }
        else if (subKey >= '0' && subKey <= '9') {
          // Mengubah nilai poin
          poin = poin * 10 + (subKey - '0');
          lcd.setCursor(0, 1);
          lcd.print(poin);
        }
      }
    }
  }
  else if (key == 'B') {
    // Menuju ke fungsi lain
  }

  delay(100);
}
