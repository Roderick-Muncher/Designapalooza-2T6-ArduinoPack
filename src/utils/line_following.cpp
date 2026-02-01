#include "devices.hpp"

void followLine(DDBot& drivetrain, ColorSensor& colorSensor, ColorName lineColor, bool trackLeft) {
  const int baseSpeed = 150;
  const int correctionSpeed = 100;

  ColorRGB colorReading = colorSensor.readNormalized();
  ColorName detectedColor = colorSensor.classify(colorReading);

  bool onLine = (detectedColor == lineColor);

  if (trackLeft) {
    (onLine) ? drivetrain.right(255) : drivetrain.left(255);
  } else {
    (onLine) ? drivetrain.left(255) : drivetrain.right(255);
  }

  delay(50);
}
