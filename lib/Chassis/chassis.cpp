#include "chassis.hpp"

/*

moveTank(): Main movement control: Forward/Backward/Turning for time (T)

readColor(): Reads and returns color from TCS230 Color Sensor

maxdistance(): Reads distance of nearest obstacle from HCSR04 UltraSonic Sensor

followLine(): Line-following program (May not be provided to students)

*/

void Chassis::moveTank(int leftSpeed, int rightSpeed, int time,
                       bool stopAfter) {

  // Set movement direction - converting speed to DDBOT commands
  if (leftSpeed >= 0 && rightSpeed >= 0) {
    drivetrain_.forward(leftSpeed, rightSpeed);
  } else if (leftSpeed < 0 && rightSpeed < 0) {
    drivetrain_.backward(-leftSpeed, -rightSpeed);
  } else if (leftSpeed >= 0 && rightSpeed < 0) {
    drivetrain_.right(leftSpeed, -rightSpeed);
  } else {
    drivetrain_.left(-leftSpeed, rightSpeed);
  }

  // Stop after certain amount of time
  delay(time);
  if (stopAfter && time > 0) {
    drivetrain_.stop();
  }
}

int Chassis::readDistance() {
  unsigned long distance =
      ultrasonic_.ping_cm(maxDistCm) * cos(ultrasonicAngle);

  // Return max distance if object out of range
  if (distance == 0) {
    distance = maxDistCm;
  }

  // // Push to queue
  // distanceReadings_.push(static_cast<int>(distance));
  // if (distanceReadings_.size() > 5) {
  //   distanceReadings_.pop();
  // }

  return static_cast<int>(distance);
}
