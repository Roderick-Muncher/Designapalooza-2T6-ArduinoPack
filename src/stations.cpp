#include "stations.hpp"

void runStationA(DDBot& drivetrain) {
  Serial.println("Running Station A");
  drivetrain.forward(255);
  delay(5500);
  drivetrain.clockwise(255);
  delay(1000);
  drivetrain.forward(255);
  delay(3000);
  drivetrain.left(255);
  // Arm down
  delay(3000);

  drivetrain.forward(100);
  delay(1000);

  // Arm up
  delay(1000);

  drivetrain.clockwise(255);
  delay(1000);
  drivetrain.forward(255);
  delay(3000);
  drivetrain.stop();
  // Arm down
  delay(1000);
  drivetrain.backward(255);
  delay(3000);
  drivetrain.clockwise(255);
  delay(2000);
  drivetrain.stop();
  delay(10000);
}
