
// const int
const int pEchA = 2;
const int pEchB = 3;

volatile long countPulses = 0;
const int TimeSampling = 10; //ms (mili secon)
unsigned long lastTime = 0;
void setup()
{
  pinMode(pEchA, INPUT);
  pinMode(pEchB, INPUT);
  attachInterrupt(pEchA, ISR_Encoder_A, RISING);
  Serial.begin(115200); // bodride persecon 115200
}

void loop()
{
  unsigned long currentTime = millis();
  float deltaTime = currentTime - lastTime;
  if (deltaTime >= TimeSampling) {
    Serial.println(countPulses);
    countPulses = 0;
    lastTime = currentTime;
  }
}

void ISR_Encoder_A()
{
  if (digitalRead(pEchB)) {
    // clockwise
    countPulses++;
  }
  else
  {
    // counter clockwise
    countPulses--;
  }
}
