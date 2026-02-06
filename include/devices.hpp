#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <ColorSensor.h>
#include <DDBot.h>

#include <chassis.hpp>

#include "constants.hpp"

inline DDBot drivetrain(drive::directionPins, drive::speedPins);
inline ColorSensor colorSensor(color::S2_PIN, color::S3_PIN, color::OUT_PIN);

inline Chassis chassis(drivetrain, colorSensor);

#endif  // DEVICES_HPP
