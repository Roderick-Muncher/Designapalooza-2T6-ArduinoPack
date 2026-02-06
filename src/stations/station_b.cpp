#include "stations.hpp"

// Shooting
void runStationB() {
  Serial.println("Running Station B");
  // Sensor polling speed is too slow to reliably measure position
  // Skip to avoid potential reset penalty or spending a long time measuring
  Serial.println("Station B complete");
}
