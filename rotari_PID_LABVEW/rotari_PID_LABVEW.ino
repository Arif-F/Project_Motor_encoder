/*volatile int rpmcount = 0;
int rpm = 0;
unsigned long lastmillis = 0;

void setup() {
  pinMode(3, OUTPUT);
  Serial.begin(115200);
  
  attachInterrupt(0, rpm_fan, FALLING);
}

void loop() {
  if (Serial.available()) {
    int a = Serial.parseInt();
    if (Serial.read() == char(13)) analogWrite(3, a);
  }
  if (millis() - lastmillis == 100) {
    detachInterrupt(0);
    Serial.println(rpmcount);
    rpmcount = 0;
    lastmillis = millis();
    attachInterrupt(0, rpm_fan, FALLING);
  }
  Serial.println("helo");
  delay(2000);
}


void rpm_fan() {
  rpmcount++;
}*/
