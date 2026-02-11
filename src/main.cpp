#include <Arduino.h>
#include <NewPing.h>

#include <chassis.hpp>
#include <color_sensor.hpp>
#include <ir_sensor.hpp>

#include "constants.hpp"

ColorSensor colorSensor(color::S2_PIN, color::S3_PIN, color::OUT_PIN);
NewPing ultrasonic(sonar::TRIGGER_PIN, sonar::ECHO_PIN, sonar::MAX_DIST_CM);
Chassis chassis(drive::DIRECTION_PINS, drive::SPEED_PINS);

void setup() {
  Serial.begin(115200);
  while (!Serial && millis() < 2000) {
  }

  Serial.println("Initializing…");
  chassis.stop();
  Serial.println("Initialization complete");

  // Put your code below:

  chassis.moveTank(255, 255, 1000);

  //

  Serial.println("Done");
}

void loop() {
  HSVColor hsv = colorSensor.read_hsv();
  Serial.println("HSV: " + String(hsv.hue) + ", " + String(hsv.saturation) + ", " +
                 String(hsv.value));
  Serial.println("Color: " + toString(colorSensor.getColorName(hsv)));

  int dist = ultrasonic.ping_cm();
  Serial.println("Distance: " + String(dist) + " cm");
  delay(1000);
}
