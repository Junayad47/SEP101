// Starship.cpp - function definitions for a warbird

#include "Starship.h"
using namespace std;

// Starship constructor with fuel level, light level, masses of passengers, cargo and workstations per payload, number of laser torpedoes and laser cannons per weapons system.
// Sets speed and distance to 0.0.
Starship::Starship(double fuelLevel, double lightLevel, double passengersPerPayload, double cargoPerPayload, double workstationsPerPayload, int torpedoesPerWeaponsSystem, int laserCannonsPerWeaponsSystem) {
    payload = Payload(passengersPerPayload, cargoPerPayload, workstationsPerPayload);
    propulsionSystem = PropulsionSystem(fuelLevel, lightLevel);
    weaponsSystem = WeaponsSystem(torpedoesPerWeaponsSystem, laserCannonsPerWeaponsSystem);

    speed = 0.0;
    distance = 0.0;
}

// Accelerates the starship to given speed.
// If there is enough fuel to do this, returns true. Returns false otherwise.
bool Starship::ChangeSpeed(double _speed) {
    double totalMass = payload.GetMass();
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
void Starship::Travel(double timeTravelled, double lightLevel) {
    distance += timeTravelled * speed;
    propulsionSystem.SetLightLevel(lightLevel);
    propulsionSystem.GenerateFuel(timeTravelled);
}

// Fires given number of torpedoes. Returns true if there's enough torpedoes, returns false otherwise.
bool Starship::FireTorpedo(int torpedoes) {
    return weaponsSystem.FireTorpedo(torpedoes);
}

// Fires laser cannons for given amount of time. Returns true if there's enough fuel to do this, returns false otherwise.
bool Starship::FireLaser(double time) {
    return propulsionSystem.ConsumeFuel(weaponsSystem.FireLaser(time));
}

// Generates a report printing the speed and the distance travelled by this ship.
// Also prints the propulsion system, payload and weapons system reports.
void Starship::GenerateReport() {
    // Make cout print floats/doubles with a fixed number of decimals.
    cout.setf(ios::fixed);
    // Sets the number to 2.
    cout.precision(2);
    cout << "The star ship is travelling at " << speed << "m/s and has travelled " << distance << "m." << endl;
    propulsionSystem.GenerateReport();
    payload.GenerateReport();
    weaponsSystem.GenerateReport();
    cout << endl;
}
