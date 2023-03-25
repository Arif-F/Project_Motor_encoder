/*#include <LiquidCrystal_I2C.h>  //Library untuk mengakses LCD
#include <Keypad.h>             //Library untuk mengakses keypad

//Inisialisasi pin motor encoder
int encoderPinA = 2;
int encoderPinB = 3;

//Variabel untuk menyimpan nilai posisi encoder
volatile long encoderPos = 0;

//Variabel untuk menyimpan nilai putaran sebelumnya
int prevEncoderPos = 0;

//Inisialisasi keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 11, 10, 9, 8 };
byte colPins[COLS] = { 7, 6, 5, 4 };
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

//Inisialisasi LCD
LiquidCrystal_I2C lcd(0X27, 16, 2);

void setup() {
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), updateEncoder, CHANGE);
  lcd.init();
  lcd.backlight();
    //lcd.begin(16, 2);
}

void loop() {
  //Membaca tombol keypad yang ditekan
  char key = keypad.getKey();

  //Jika tombol ditekan, tampilkan nilai putaran dan kecepatan motor pada LCD
  if (key != NO_KEY) {
    lcd.clear();
    lcd.print("Encoder Pos: ");
    lcd.print(encoderPos);
    lcd.setCursor(0, 1);
    lcd.print("Motor RPM: ");
    lcd.print(getMotorRPM());
  }
}

//Fungsi untuk menghitung putaran motor dan kecepatan putaran
int getMotorRPM() {
  int encoderDelta = encoderPos - prevEncoderPos;
  int motorRPM = encoderDelta * 60 / 12;  //12 adalah jumlah impuls per putaran pada encoder yang digunakan
  prevEncoderPos = encoderPos;
  return motorRPM;
}

//Fungsi yang dipanggil ketika terjadi perubahan pada sinyal encoder
void updateEncoder() {
  if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
    encoderPos++;
  } else {
    encoderPos--;
  }
}
*/