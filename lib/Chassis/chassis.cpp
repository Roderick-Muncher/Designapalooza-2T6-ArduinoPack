#include "chassis.hpp"

ColorName Chassis::readColor() {
  ColorRGB colorReading = colorSensor.readNormalized();
  return colorSensor.classify(colorReading);
}

void Chassis::followLine(ColorName lineColor, bool followLeft,
                         std::pair<int, int> speeds, bool reverse) {
  auto [inSpeed, outSpeed] = speeds;

  bool onLine = (readColor() == lineColor);

  // If following left side move left if on the line, right if off the line
  // Vice-versa for following right
  // Reversing uses backward instead and flips motor order
  if (reverse) {
    if (followLeft == onLine) {
      drivetrain.backward(outSpeed, inSpeed);
    } else {
      drivetrain.backward(inSpeed, outSpeed);
    }
  } else {
    if (followLeft == onLine) {
      drivetrain.forward(inSpeed, outSpeed);
    } else {
      drivetrain.forward(outSpeed, inSpeed);
    }
  }
}
