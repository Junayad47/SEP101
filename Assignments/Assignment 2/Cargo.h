// Cargo.h - class declaration for a cargo ship

#ifndef _CARGO_H_
#define _CARGO_H_

#include <iostream>

#include "components/Payload.h"
#include "components/PropulsionSystem.h"

class Cargo {
    Payload payload1, payload2;
    PropulsionSystem propulsionSystem;

    double speed;
    double distance;

   public:
    Cargo(double fuelLevel, double lightLevel, double passengersPerPayload, double cargoPerPayload, double workstationsPerPayload);

    bool ChangeSpeed(double _speed);
    void Travel(double timeTravelled, double lightLevel);

    void GenerateReport();
};

#endif
