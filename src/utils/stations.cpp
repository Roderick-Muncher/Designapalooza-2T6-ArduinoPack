#include "stations.hpp"

void runStationA(Chassis& chassis) {
  Serial.println("Running Station A");
  // Move to blue tape
  while (chassis.readColor() != ColorName::BLUE) {
    chassis.followLine(ColorName::GREEN, false);
  }
  // Hardcoded box pickup

}


