// PropulsionSystem.h - class declaration for a propulsion system

#ifndef _PROPULSIONSYSTEM_H_
#define _PROPULSIONSYSTEM_H_

#include <iostream>

class PropulsionSystem {
    // Fixed static constant variables.
    static constexpr double TANK_CAPACITY = 1000.0;
    static constexpr double SPEED_OF_LIGHT = 299792458.0;

    double fuelLevel;
    double lightLevel;

   public:
    PropulsionSystem();
    PropulsionSystem(double _fuelLevel, double _lightLevel);

    bool ConsumeFuel(double energy);
    void AddFuel(double fuel);
    void GenerateFuel(double time);
    void SetLightLevel(double _lightLevel);

    void GenerateReport();
};

#endif
