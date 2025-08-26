#include <Stepper.h>
// 28BYJ-48 has 2048 steps per full revolution (in half-step mode)
const int STEPS_PER_REV = 2048;

// ULN2003 pins
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;

Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

void setup() {
  stepper.setSpeed(10);  // motor speed (RPM)

  unsigned long startTime = millis();

  // Pull finger down for 20s
  while (millis() - startTime < 27000) {
    stepper.step(-1);  // negative = pull down
  }

  delay(500);  // short pause

  // Reset timer
  startTime = millis();

  // Release finger up for 20s
  while (millis() - startTime < 20000) {
    stepper.step(1);  // positive = release up
  }

  // Stop forever
  while (true) {
    // do nothing
  }
}
