#ifndef CHASSIS_HPP
#define CHASSIS_HPP
#include <DDBot.h>
#include <NewPing.h>
#include <color_sensor.hpp>

#include <cmath>
#include <queue>

class Chassis {

 public:

  /**
   * @brief Construct a new Chassis object
   * @param drivetrain Reference to the DDBot drivetrain instance
   * @param sensor Reference to the ColourSensor instance
   * @param ultrasonic Reference to the NewPing ultrasonic sensor instance
   */
  Chassis(DDBot& drivetrain, ColorSensor& sensor, NewPing& ultrasonic)
      : drivetrain_(drivetrain),
        colorSensor_(sensor),
        ultrasonic_(ultrasonic) {}

  /**
   * @brief Move the robot using tank controls without direction flipping
   * @param leftSpeed Speed for the left motor (-255 to 255)
   * @param rightSpeed Speed for the right motor (-255 to 255)
   * @param time Duration to move in milliseconds
   * @param stopAfter If true, stop the robot after moving for the specified time
   */

  void moveTank(int leftSpeed, int rightSpeed, int time = 0,
                bool stopAfter = true);

  /**
   * @brief Stop all movement of the robot
   */

  void stop() { drivetrain_.stop(); }

  /**
   * @brief Read the current distance measured by the ultrasonic sensor
   * @return Distance in centimeters
   */

  int readDistance();

 protected:
  DDBot& drivetrain_;
  ColorSensor& colorSensor_;
  NewPing& ultrasonic_;

  const int maxDistCm = 30;
  const double ultrasonicAngle = 20.0 * (M_PI / 180.0);  // deg converted to rad
};

#endif  // CHASSIS_HPP
