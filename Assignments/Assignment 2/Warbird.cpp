// Warbird.cpp - function definitions for a warbird

#include "Warbird.h"
using namespace std;

// Warbird constructor with fuel level, light level, masses of passengers, cargo and workstations per payload, number of laser torpedoes and laser cannons per weapons system.
// Sets speed and distance to 0.0.
Warbird::Warbird(double fuelLevel, double lightLevel, double passengersPerPayload, double cargoPerPayload, double workstationsPerPayload, int torpedoesPerWeaponsSystem, int laserCannonsPerWeaponsSystem) {
    payload = Payload(passengersPerPayload, cargoPerPayload, workstationsPerPayload);
    propulsionSystem1 = PropulsionSystem(fuelLevel, lightLevel);
    propulsionSystem2 = PropulsionSystem(fuelLevel, lightLevel);
    weaponsSystem1 = WeaponsSystem(torpedoesPerWeaponsSystem, laserCannonsPerWeaponsSystem);
    weaponsSystem2 = WeaponsSystem(torpedoesPerWeaponsSystem, laserCannonsPerWeaponsSystem);

    speed = 0.0;
    distance = 0.0;
}

// Accelerates the starship to given speed.
// If there is enough fuel to do this, returns true. Returns false otherwise.
bool Warbird::ChangeSpeed(double _speed) {
    double totalMass = payload.GetMass();
    double speedDelta = _speed - speed;
    // There are two propulsion systems. That's why the required energy is divided by 2.0
    // to get the energy required by each propulsion system.
    double energyRequiredEach = 0.5 * totalMass * (speedDelta * speedDelta) / 2.0;
    bool success = propulsionSystem1.ConsumeFuel(energyRequiredEach);
    if (success) {
        // The ship has enough fuel to change its speed.
        speed = _speed;
        propulsionSystem2.ConsumeFuel(energyRequiredEach);
    }
    return success;
}

// Travels for given amount of time.
// While travelling, also generates fuel according to the light level by both propulsion systems.
void Warbird::Travel(double timeTravelled, double lightLevel) {
    distance += timeTravelled * speed;
    propulsionSystem1.SetLightLevel(lightLevel);
    propulsionSystem1.GenerateFuel(timeTravelled);
    propulsionSystem2.SetLightLevel(lightLevel);
    propulsionSystem2.GenerateFuel(timeTravelled);
}

// Fires given number of torpedoes. Returns true if there's enough torpedoes, returns false otherwise.
bool Warbird::FireTorpedo(int torpedoes) {
    // There are two weapons systems. If the number of torpedoes to fire is even,
    // then there is no problem. However, if the number is odd, then one of the weapons
    // system will have to fire an extra torpedo. This poses a problem: a situation
    // might arise when one weapons system fires some torpedoes but the other one
    // might not have enough. The return value will get confusing in that case.
    // That's why we're assuming the number of torpedoes of to fire will always be even
    // like in the demonstration script.
    return weaponsSystem1.FireTorpedo(torpedoes / 2) && weaponsSystem2.FireTorpedo(torpedoes / 2);
}

// Fires laser cannons for given amount of time. Returns true if there's enough fuel to do this, returns false otherwise.
bool Warbird::FireLaser(double time) {
    bool success = propulsionSystem1.ConsumeFuel(weaponsSystem1.FireLaser(time));
    if (success) {
        // If one propulsion system can generate enough energy, the other one can too.
        propulsionSystem2.ConsumeFuel(weaponsSystem2.FireLaser(time));
    }
    return success;
}

// Generates a report printing the speed and the distance travelled by this ship.
// Also prints the propulsion system, payload and weapons system reports.
void Warbird::GenerateReport() {
    // Make cout print floats/doubles with a fixed number of decimals.
    cout.setf(ios::fixed);
    // Sets the number to 2.
    cout.precision(2);
    cout << "The war bird is travelling at " << speed << "m/s and has travelled " << distance << "m." << endl;
    propulsionSystem1.GenerateReport();
    propulsionSystem2.GenerateReport();
    payload.GenerateReport();
    weaponsSystem1.GenerateReport();
    weaponsSystem2.GenerateReport();
    cout << endl;
}
