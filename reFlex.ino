#include <Stepper.h>

// 28BYJ-48 has 2048 steps per revolution (with gearbox)
const int stepsPerRevolution = 2048;

// connect motor control pins to Arduino
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(10); // RPM (try 10 first)
  Serial.begin(9600);
}

void loop() {
  Serial.println("Clockwise");
  myStepper.step(stepsPerRevolution);  // one full revolution
  delay(1000);

  Serial.println("Counterclockwise");
  myStepper.step(-stepsPerRevolution); // one full revolution back
  delay(1000);
}
