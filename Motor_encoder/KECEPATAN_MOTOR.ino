

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int half_revolutions = 0;
int rpm = 0;
unsigned long lastmillis = 0;
int col1 = 7;
int col2 = 6;
int col3 = 5;
int col4 = 4;
int row1 = 11;
int row2 = 10;
int row3 = 9;
int row4 = 8;
int buttonState_row1 = 0;
int buttonState_row2 = 0;
int buttonState_row3 = 0;
int buttonState_row4 = 0;
long int nilai = 0, value, array[10];
int i, a, j, indeks = 0;
char temp[16];
void read_button() {
  buttonState_row1 = digitalRead(row1);
  buttonState_row2 = digitalRead(row2);
  buttonState_row3 = digitalRead(row3);
  buttonState_row4 = digitalRead(row4);
}
void simpan_variabel() {
  if (i == 1) {
    nilai = array[i];
    //itoa(array[i],temp);
    lcd.setCursor(i + 6, 0);
    lcd.print(array[i]);
    //Serial.print(array[i]);
    delay(500);
    //lcd.setCursor(i+6,0);
    //lcd.print("*");
    //Serial.print("*");
  }
  if (i >= 2 && i <= 8) {
    nilai = (nilai * 10) + array[i];
    //itoa(array[i],temp);
    lcd.setCursor(i + 6, 0);
    lcd.print(array[i]);
    delay(500);
    //Serial.print(array[i]);
    //delay(500);
    //lcd.setCursor(i+5,0);
    //lcd.print("*");
    //Serial.print("*");
  }
}
void hapus() {
  //c++;
  nilai = (nilai - array[i]) / 10;
  //itoa(nilai,temp);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Target:");
  /*for(a=0;a<i;a++){
lcd.setCursor(a,1);
lcd.print("*");
} */
  lcd.setCursor(7, 0);
  lcd.print(nilai);
}
void enter() {
  indeks = 1;
  lcd.setCursor(0, 1);
  lcd.print("OK");
  Serial.print("b");
  Serial.println(nilai);
  //lcd.clear();
}
void keypad() {
  //lcd.setCursor(0,0);
  read_button();
  digitalWrite(col1, LOW);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, HIGH);
  delay(50);
  if (buttonState_row1 == LOW) { delay(50); }  //1 //i++; array[i]=1; simpan_dlm_1variabel(); delay_ms(300);
  else if (buttonState_row2 == LOW) {
    i++;
    array[i] = 3;
    simpan_variabel();
    delay(50);
  }  //4
  else if (buttonState_row3 == LOW) {
    i++;
    array[i] = 2;
    simpan_variabel();
    delay(50);
  }  //7
  else if (buttonState_row4 == LOW) {
    i++;
    array[i] = 1;
    simpan_variabel();
    delay(50);
  }  //* //A
  read_button();
  digitalWrite(col1, HIGH);
  digitalWrite(col2, LOW);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, HIGH);
  delay(50);
  if (buttonState_row1 == LOW) {
    i--;
    hapus();
    delay(50);
  }                                                 //1 //i++; array[i]=1; simpan_dlm_1variabel(); delay_ms(300);
  else if (buttonState_row2 == LOW) { delay(50); }  //4
  else if (buttonState_row3 == LOW) {
    i++;
    array[i] = 0;
    simpan_variabel();
    delay(50);
  }  //7
  else if (buttonState_row4 == LOW) {
    enter();
    delay(50);
  }  //* //A
  read_button();
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, LOW);
  digitalWrite(col4, HIGH);
  delay(50);
  if (buttonState_row1 == LOW) { delay(50); }  //1 //i++; array[i]=1; simpan_dlm_1variabel(); delay_ms(300);
  else if (buttonState_row2 == LOW) {
    i++;
    array[i] = 9;
    simpan_variabel();
    delay(50);
  }  //4
  else if (buttonState_row3 == LOW) {
    i++;
    array[i] = 8;
    simpan_variabel();
    delay(50);
  }  //7
  else if (buttonState_row4 == LOW) {
    i++;
    array[i] = 7;
    simpan_variabel();
    delay(50);
  }  //* //A
  read_button();
  digitalWrite(col1, HIGH);
  digitalWrite(col2, HIGH);
  digitalWrite(col3, HIGH);
  digitalWrite(col4, LOW);
  delay(50);
  if (buttonState_row1 == LOW) { delay(50); }  //1 //i++; array[i]=1; simpan_dlm_1variabel(); delay_ms(300);
  else if (buttonState_row2 == LOW) {
    i++;
    array[i] = 6;
    simpan_variabel();
    delay(50);
  }  //4
  else if (buttonState_row3 == LOW) {
    i++;
    array[i] = 5;
    simpan_variabel();
    delay(50);
  }  //7
  else if (buttonState_row4 == LOW) {
    i++;
    array[i] = 4;
    simpan_variabel();
    delay(50);
  }  //* //A
}
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(col4, OUTPUT);
  pinMode(row1, INPUT_PULLUP);
  pinMode(row2, INPUT_PULLUP);
  pinMode(row3, INPUT_PULLUP);
  pinMode(row4, INPUT_PULLUP);
  lcd.begin(16, 2);
attachInterrupt(0, rpm_fan, FALLING);
if (millis() - lastmillis == 1000){ //Uptade every one second, this will be equal to reading frecuency (Hz).
detachInterrupt(0);//Disable interrupt when calculating
rpm = half_revolutions * 15; // Convert frecuency to RPM, note: this works for one interruption per full rotation. For two interrups per full rotation use half_revolutions * 30.
Serial.print("RPM =\t"); //print the word "RPM" and tab.
Serial.println(rpm); // print the rpm value.
Serial.print("\t Hz=\t"); //print the word "Hz".
Serial.println(half_revolutions); //print revolutions per second or Hz. And print new line or enter.
half_revolutions = 0; // Restart the RPM counter
lastmillis = millis(); // Uptade lasmillis
attachInterrupt(0, rpm_fan, FALLING); //enable interrupt
}
}
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Target:");
  keypad();
}

void rpm_fan(){
half_revolutions++;
}