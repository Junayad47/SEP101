// Warbird.h - class declaration for a warbird

#ifndef _WARBIRD_H_
#define _WARBIRD_H_

#include <iostream>

#include "components/Payload.h"
#include "components/PropulsionSystem.h"
#include "components/WeaponsSystem.h"

class Warbird {
    Payload payload;
    PropulsionSystem propulsionSystem1, propulsionSystem2;
    WeaponsSystem weaponsSystem1, weaponsSystem2;

    double speed;
    double distance;

   public:
    Warbird(double fuelLevel, double lightLevel, double passengersPerPayload, double cargoPerPayload, double workstationsPerPayload, int torpedoesPerWeaponsSystem, int laserCannonsPerWeaponsSystem);

    bool ChangeSpeed(double _speed);
    void Travel(double timeTravelled, double lightLevel);
    bool FireTorpedo(int torpedoes);
    bool FireLaser(double time);

    void GenerateReport();
};

#endif
