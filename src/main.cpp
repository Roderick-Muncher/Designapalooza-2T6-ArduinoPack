#include <Arduino.h>
#include "devices.hpp"

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 2000) {}

  Serial.println("Initializing…");
  drivetrain.setPinModes();
  chassis.stop();
  Serial.println("Initialization complete");

  // Put your code in here:







  


  //

  Serial.println("Done");

}

void loop() {}
