// PropulsionSystem.cpp - function definitions for a propulsion system

#include "PropulsionSystem.h"

using namespace std;

// Propulsion system constructor with default parameters (fuel level and light level set to 0.0).
PropulsionSystem::PropulsionSystem() {
    fuelLevel = 0.0;
    lightLevel = 0.0;
}

// Propulsion system constructor with fuel level and light level.
PropulsionSystem::PropulsionSystem(double _fuelLevel, double _lightLevel) {
    fuelLevel = _fuelLevel;
    lightLevel = _lightLevel;
}

// If the energy can be made from the available fuel, do that and return true.
// Otherwise return false.
bool PropulsionSystem::ConsumeFuel(double energy) {
    double fuel_required = energy / (SPEED_OF_LIGHT * SPEED_OF_LIGHT);
    if (fuel_required <= fuelLevel) {
        fuelLevel -= fuel_required;
        return true;
    }
    return false;
}

// Adds fuel to the existing fuel level.
// If the fuel level overflows the tank capacity, keeps the maximum level.
void PropulsionSystem::AddFuel(double fuel) {
    fuelLevel += fuel;

    // Fuel level cannot go higher than the tank capacity
    fuelLevel = min(fuelLevel, TANK_CAPACITY);
}

// Generates fuel, the amount is light level times the seconds passed.
// If the fuel level overflows the tank capacity, keeps the maximum level.
void PropulsionSystem::GenerateFuel(double time) {
    fuelLevel += time * lightLevel;

    // Fuel level cannot go higher than the tank capacity
    fuelLevel = min(fuelLevel, TANK_CAPACITY);
}

// Sets the light level.
void PropulsionSystem::SetLightLevel(double _lightLevel) {
    lightLevel = _lightLevel;
}

// Generates a report printing the fuel level in kg and light level.
void PropulsionSystem::GenerateReport() {
    // Make cout print floats/doubles with a fixed number of decimals.
    cout.setf(ios::fixed);
    // Sets the number to 2.
    cout.precision(2);
    cout << "Propulsion: fuel level: " << fuelLevel << "kg of matter/anti-matter, light level:" << lightLevel << "." << endl;
}
