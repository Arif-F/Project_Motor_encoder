#include <Key.h>
#include <Keypad.h>


const byte ROWS = 4; // Jumlah baris keypad
const byte COLS = 4; // Jumlah kolom keypad

char keys[ROWS][COLS] = { // Daftar tombol keypad
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; // Pin baris keypad
byte colPins[COLS] = {9, 8, 7, 6}; // Pin kolom keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // Inisialisasi keypad

int setPoint = 0; // Set point awal

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key == 'A') { // Masuk ke submenu
    int submenuChoice = 0;
    while (submenuChoice != 3) { // Selama belum keluar dari submenu
      Serial.println("Submenu:");
      Serial.println("1. Set Point");
      Serial.println("2. Lihat Set Point");
      Serial.println("3. Keluar");
      char submenuKey = keypad.getKey();
      if (submenuKey == '1') { // Ubah set point
        Serial.println("Masukkan set point (0-255):");
        while (keypad.getState() != IDLE) { // Tunggu sampai tombol dilepas
          char setPointKey = keypad.getKey();
          if (setPointKey >= '0' && setPointKey <= '9') { // Jika tombol angka ditekan
            setPoint = setPoint * 10 + (setPointKey - '0'); // Update set point
            if (setPoint > 255) { // Batasi nilai set point
              setPoint = 255;
            }
            Serial.print("\rSet point: ");
            Serial.print(setPoint);
          }
        }
      } else if (submenuKey == '2') { // Lihat set point
        Serial.print("\rSet point: ");
        Serial.print(setPoint);
      } else if (submenuKey == '3') { // Keluar dari submenu
        submenuChoice = 3;
      }
    }
  }
}
