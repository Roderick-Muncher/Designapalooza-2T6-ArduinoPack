#include <Arduino.h>
#include "devices.hpp"
#include "stations.hpp"

Station currentStation = Station::STATION_A;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial && millis() < 2000) {}
  
  Serial.println("Initializing");
  drivetrain.setPinModes();
  delay(3000);

  switch (currentStation) {
    case Station::STATION_A:
      runStationA(drivetrain);
      break;
    default:
      Serial.println("No station selected or station not implemented.");
      break;
  }
}

void loop() {
}
