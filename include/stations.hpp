#ifndef STATIONS_HPP
#define STATIONS_HPP

#include <DDBot.h>

enum class Station {
    NONE,
    STATION_A,
    STATION_B,
    STATION_C,
    STATION_D
};

void runStationA(DDBot& drivetrain);

#endif // STATIONS_HPP
