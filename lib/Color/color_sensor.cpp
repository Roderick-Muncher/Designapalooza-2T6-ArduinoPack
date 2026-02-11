#include "color_sensor.hpp"

ColorName ColorSensor::getColorName(const HSVColor& hsv) const {
  if (red_range.contains(hsv)) {
    return ColorName::RED;
  } else if (green_range.contains(hsv)) {
    return ColorName::GREEN;
  } else if (blue_range.contains(hsv)) {
    return ColorName::BLUE;
  } else if (black_range.contains(hsv)) {
    return ColorName::BLACK;
  } else if (brown_range.contains(hsv)) {
    return ColorName::BROWN;
  } else if (white_range.contains(hsv)) {
    return ColorName::WHITE;
  } else {
    return ColorName::UNKNOWN;
  }
}

