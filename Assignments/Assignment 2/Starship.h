// Starship.h - class declaration for a starship

#ifndef _STARSHIP_H_
#define _STARSHIP_H_

#include <iostream>

#include "components/Payload.h"
#include "components/PropulsionSystem.h"
#include "components/WeaponsSystem.h"

class Starship {
    Payload payload;
    PropulsionSystem propulsionSystem;
    WeaponsSystem weaponsSystem;

    double speed;
    double distance;

   public:
    Starship(double fuelLevel, double lightLevel, double passengersPerPayload, double cargoPerPayload, double workstationsPerPayload, int torpedoesPerWeaponsSystem, int laserCannonsPerWeaponsSystem);

    bool ChangeSpeed(double _speed);
    void Travel(double timeTravelled, double lightLevel);
    bool FireTorpedo(int torpedoes);
    bool FireLaser(double time);

    void GenerateReport();
};

#endif
