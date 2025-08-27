#include <Stepper.h>

// --- Stepper setup ---
const int STEPS_PER_REV = 2048;  // 28BYJ-48 half-step
const int IN1 = 8;
const int IN2 = 9;
const int IN3 = 10;
const int IN4 = 11;
Stepper stepper(STEPS_PER_REV, IN1, IN3, IN2, IN4);

// --- Flex sensor setup ---
const int FLEX_PIN = A0;
int flexValue = 0;
int prevFlexValue = 0;

// --- Mapping values ---
const int FLEX_MIN = 11;    // straight finger
const int FLEX_MAX = 640;   // fully bent finger
const int STEP_MIN = 0;     // stepper position when finger open
const int STEP_MAX = 50;    // adjust if your finger needs more steps

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(10);  // adjust 5–15 RPM for torque
}

void loop() {
  // 1. Read flex sensor
  flexValue = analogRead(FLEX_PIN);

  // 2. Constrain to safe range
  flexValue = constrain(flexValue, FLEX_MIN, FLEX_MAX);

  // 3. Filter small random fluctuations
  if (abs(flexValue - prevFlexValue) < 5) {
    flexValue = prevFlexValue;
  }

  // 4. Map sensor value to stepper steps
  int targetStep = map(flexValue, FLEX_MIN, FLEX_MAX, STEP_MIN, STEP_MAX);

  // 5. Constrain stepper movement
  targetStep = constrain(targetStep, STEP_MIN, STEP_MAX);

  // 6. Move stepper incrementally
  int stepDiff = targetStep - prevFlexValue;
  if (stepDiff != 0) {
    stepper.step(stepDiff);  // move forward or backward
    prevFlexValue = targetStep;
  }

  Serial.print("Flex: "); Serial.print(flexValue);
  Serial.print(" | Step: "); Serial.println(prevFlexValue);

  delay(20);  // small delay for smooth motion
}
