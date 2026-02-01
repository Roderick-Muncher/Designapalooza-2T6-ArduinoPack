#ifndef LINE_FOLLOWING_HPP
#define LINE_FOLLOWING_HPP

#include "devices.hpp"

/**
 * @brief Follow a line of a specified color using the color sensor
 * @param drivetrain Reference to the DDBot drivetrain object
 * @param colorSensor Reference to the ColorSensor object
 * @param lineColor The color of the line to follow
 * @param trackLeft If true, the robot will track the line on the left side of the robot
 *                  Otherwise, it will track the line on the right side
 */
void followLine(DDBot& drivetrain, ColorSensor& colorSensor, ColorName lineColor, bool trackLeft = true);

#endif // LINE_FOLLOWING_HPP
