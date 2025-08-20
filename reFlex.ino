#include <Servo.h>

Servo finger;
const int servoPin = 9;

const int openAngle  = 0;    // Pulley in open position—
const int closeAngle = 100;  // Adjust until finger fully closes comfortably

const int stepDeg    = 2;     // Smaller angle steps = smoother motion
const int stepDelay  = 20;    // ms delay between steps (tweak for smoothness)

void setup() {
  finger.attach(servoPin);
  finger.write(openAngle);
  delay(500);  // Let it settle
}

void loop() {
  // --- Rotate CCW to close (openAngle → closeAngle) ---
  for (int a = openAngle; a <= closeAngle; a += stepDeg) {
    finger.write(a);
    delay(stepDelay);
  }
  delay(800); // Hold closed briefly

  // --- Rotate CW to open (closeAngle → openAngle) ---
  for (int a = closeAngle; a >= openAngle; a -= stepDeg) {
    finger.write(a);
    delay(stepDelay);
  }
  delay(800); // Hold open briefly
}
