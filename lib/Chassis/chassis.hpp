#ifndef CHASSIS_HPP
#define CHASSIS_HPP
#include <ColorSensor.h>
#include <DDBot.h>

#include <queue>

struct Chassis {
  /**
   * @brief Construct a new Chassis object
   * @param drivetrain Reference to the DDBot drivetrain instance
   * @param sensor Reference to the ColorSensor instance
   */
  Chassis(DDBot& drivetrain, ColorSensor& sensor)
      : drivetrain_(drivetrain), colorSensor_(sensor) {}

  /**
   * @brief Move the robot using tank controls without direction flipping
   * @param leftSpeed Speed for the left motor (-255 to 255)
   * @param rightSpeed Speed for the right motor (-255 to 255)
   */
  void moveTank(int leftSpeed, int rightSpeed);

  /**
   * @brief Read the current color detected by the color sensor
   * @return Detected ColorName enum
   */
  ColorName readColor();

  /**
   * @brief Follow a line of the specified color using a single colour sensor by
   * weaving along an edge.
   * @param lineColor Color of the line to follow
   * @param followLeft If true, follow the line's left side (in the direction of
   * travel); if false, follow the right side
   * @param speeds Pair of speeds (inSpeed, outSpeed) in range [0, 255]
   * @param reverse If true, move backwards while following the line
   * @note This method must be called repeatedly with a delay in between
   */
  void followLine(ColorName lineColor, bool followLeft,
                  std::pair<int, int> speeds = {100, 150},
                  bool reverse = false);

  DDBot& drivetrain_;
  ColorSensor& colorSensor_;
};

#endif  // CHASSIS_HPP
