#include <Arduino.h>
#include <DDBot.h>
#include "constants.hpp"

DDBot drivetrain(dt::directionPins, dt::speedPins);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial && millis() < 2000) {}

  Serial.println("Testing (pls work)");
  
  drivetrain.setPinModes();
  delay(3000);
}

void loop() {
  drivetrain.forward(255);
  delay(6000);
  drivetrain.stop();
  delay(100);
  drivetrain.right(255);
  delay(2000);
  drivetrain.stop();
  delay(10000);
}
