#ifndef COLOR_SENSOR_HPP
#define COLOR_SENSOR_HPP
#include <TCS3200.h>

#include <map>

#include "color_utils.hpp"

enum class ColorName { RED, GREEN, BLUE, BLACK, BROWN, WHITE, UNKNOWN };

String toString(ColorName color) {
  switch (color) {
    case ColorName::RED:
      return "Red";
    case ColorName::GREEN:
      return "Green";
    case ColorName::BLUE:
      return "Blue";
    case ColorName::BLACK:
      return "Black";
    case ColorName::BROWN:
      return "Brown";
    case ColorName::WHITE:
      return "White";
    default:
      return "Unknown";
  }
}

class ColorSensor : public TCS3200 {
 public:
  ColorSensor(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t outPin)
      : TCS3200(s0, s1, s2, s3, outPin) {}
  ColorSensor(uint8_t s2, uint8_t s3, uint8_t outPin)
      : TCS3200(-1, -1, s2, s3, outPin) {}

  /**
   * @brief Classify the color based on HSV ranges
   * @param hsv HSV color to classify
   * @return
   */
  ColorName getColorName(const HSVColor& hsv) const;

  HSVColorRange red_range{{345, 0.5, 0.4}, {15, 1.0, 1.0}};    // Around 0°
  HSVColorRange green_range{{80, 0.4, 0.3}, {140, 1.0, 1.0}};  // 80-140°
  HSVColorRange blue_range{{200, 0.4, 0.3}, {260, 1.0, 1.0}};  // 200-260°
  HSVColorRange black_range{{0, 0, 0}, {360, 1.0, 0.2}};       // low value
  HSVColorRange brown_range{{10, 0.4, 0.2}, {30, 1.0, 0.6}};   // dark orange
  HSVColorRange white_range{{0, 0, 0.8}, {360, 0.2, 1.0}};     // high value
};

#endif  // COLOR_SENSOR_HPP
