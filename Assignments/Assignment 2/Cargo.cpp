// Cargo.cpp - function definitions for a cargo ship

#include "Cargo.h"
using namespace std;

// Cargo constructor with fuel level, light level, masses of passengers, cargo and workstations per payload.
// Sets speed and distance to 0.0.
Cargo::Cargo(double fuelLevel, double lightLevel, double passengersPerPayload, double cargoPerPayload, double workstationsPerPayload) {
    payload1 = Payload(passengersPerPayload, cargoPerPayload, workstationsPerPayload);
    payload2 = Payload(passengersPerPayload, cargoPerPayload, workstationsPerPayload);
    propulsionSystem = PropulsionSystem(fuelLevel, lightLevel);

    speed = 0.0;
    distance = 0.0;
}

// Accelerates the cargo ship to given speed.
// If there is enough fuel to do this, returns true. Returns false otherwise.
bool Cargo::ChangeSpeed(double _speed) {
    double totalMass = payload1.GetMass() + payload2.GetMass();
    double speedDelta = _speed - speed;
    double energyRequired = 0.5 * totalMass * (speedDelta * speedDelta);
    bool success = propulsionSystem.ConsumeFuel(energyRequired);
    if (success) {
        // The ship has enough fuel to change its speed.
        speed = _speed;
    }
    return success;
}

// Travels for given amount of time.
// While travelling, also generates fuel according to the light level.
void Cargo::Travel(double timeTravelled, double lightLevel) {
    distance += timeTravelled * speed;
    propulsionSystem.SetLightLevel(lightLevel);
    propulsionSystem.GenerateFuel(timeTravelled);
}

// Generates a report printing the speed and the distance travelled by this ship.
// Also prints the propulsion system and payload reports.
void Cargo::GenerateReport() {
    // Make cout print floats/doubles with a fixed number of decimals.
    cout.setf(ios::fixed);
    // Sets the number to 2.
    cout.precision(2);
    cout << "The cargo ship is travelling at " << speed << "m/s and has travelled " << (distance / 1000.0) << "km." << endl;
    propulsionSystem.GenerateReport();
    payload1.GenerateReport();
    payload2.GenerateReport();
    cout << endl;
}
