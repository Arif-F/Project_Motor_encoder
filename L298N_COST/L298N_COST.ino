
// Motor Two
int enB = 3; // enable pin should be connected to Arduino PWM pin
int IN3 = 5;
int IN4 = 6;
void setup () {
// Set all the motor contol pins as outputs
pinMode (enB, OUTPUT);
pinMode (IN3, OUTPUT);
pinMode (IN4, OUTPUT);
Serial.begin(9600);
}
void demoOne () {
/* This function will run the motor in both directions
at a fixed speed
*/
// Turn ON Motor Two
digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW);
// Set speed to 200 out of possible range (0 - 255)
analogWrite (enB, 200);
delay (2000);
// Now, change motor directions
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH);
delay (2000);
// Now, turn OFF Motors
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
}
void demoTwo () {
/* * This function will run the motors across the range of
possible speeds
* Note that maximum speed is determined by the motor itself
and the operating voltage
* The PWM values sent by "analogWrite ()" are functions of
the maximum speed possible by the hardware
*/
// Turn ON motor
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH);
// Decelerate from maximum speed to zero
for (int i = 100; i >= 0; i --) { // 200
analogWrite (enB, i);
delay (20);
Serial.println("clockwise");
}
// Now, turn OFF motor
digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
}
void loop () {
demoOne ();
delay (2000);
demoTwo ();
delay (2000);
}
