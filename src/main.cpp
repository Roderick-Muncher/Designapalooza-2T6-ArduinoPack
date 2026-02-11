#include <Arduino.h>
#include <NewPing.h>

#include <chassis.hpp>
#include <color_sensor.hpp>
#include <ir_sensor.hpp>

#include "constants.hpp"

// ColorSensor colorSensor(color::S2_PIN, color::S3_PIN, color::OUT_PIN);
NewPing ultrasonic(sonar::TRIGGER_PIN, sonar::ECHO_PIN, sonar::MAX_DIST_CM);
Chassis chassis(drive::DIRECTION_PINS, drive::SPEED_PINS);

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 2000) {
  }

  Serial.println("Initializing…");
  chassis.stop();
  Serial.println("Initialization complete");
  delay(1000);

  // Put your code below:
  chassis.moveTank(50, 50, 0, false);
  
  // Wait until near target
  Serial.println("Distance: " + String(ultrasonic.ping_cm()));
  while (!ultrasonic.ping_cm() || ultrasonic.ping_cm() > 25) {
    Serial.println("Distance: " + String(ultrasonic.ping_cm()));
    delay(30);
  }
  chassis.stop();
  delay(500);
  
  chassis.moveTank(-40, 40, 600);
  delay(500);
  chassis.stop();
  delay(500);
  chassis.moveTank(50, 50, 1000, true);
  delay(500);

  Serial.println("Done");
}

void loop() {
  // HSVColor hsv = colorSensor.read_hsv();
  // Serial.println("HSV: " + String(hsv.hue) + ", " + String(hsv.saturation) + ", " +
  //                String(hsv.value));
  // Serial.println("Color: " + toString(colorSensor.getColorName(hsv)));

  // int dist = ultrasonic.ping_cm();
  // Serial.println("Distance: " + String(dist) + " cm");
  delay(1000);
}
