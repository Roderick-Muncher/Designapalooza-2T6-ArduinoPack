#include "constants.hpp"
#include <DDBot.h>
#include <tcs3200.h>

extern DDBot drivetrain(drive::directionPins, drive::speedPins);
extern tcs3200 colorSensor(colour::S2, colour::S3, colour::OUT);
