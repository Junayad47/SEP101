// WeaponsSystem.cpp - function definitions for a propulsion system

#include "WeaponsSystem.h"
using namespace std;

// Weapons system constructor with default parameters (torpedoes and laser cannons set to 0)
WeaponsSystem::WeaponsSystem() {
    torpedoes = 0;
    laserCannons = 0;
}

// Weapons system constructor with the number of torpedoes and laser cannons.
WeaponsSystem::WeaponsSystem(int _torpedoes, int _laserCannons) {
    torpedoes = _torpedoes;
    laserCannons = _laserCannons;
}

// Fires given number of torpedoes. If the number of torpedoes is available, returns true.
// Otherwise returns false.
bool WeaponsSystem::FireTorpedo(int _torpedoes) {
    if (_torpedoes <= torpedoes) {
        torpedoes -= _torpedoes;
        return true;
    }
    return false;
}

// Fires laser cannons for given time. Returns the amount of energy needed.
double WeaponsSystem::FireLaser(double time) {
    return time * ENERGY_PER_SECOND;
}

// Adds torpedoes to the system. If the number exceeds capacity, sets maximum.
void WeaponsSystem::AddTorpedoes(int _torpedoes) {
    torpedoes += _torpedoes;

    // Torpedoes cannot go higher than the torpedo capacity
    torpedoes = min(torpedoes, TORPEDO_CAPACITY);
}

// Adds laser cannons to the system. If the number exceeds capacity, sets maximum.
void WeaponsSystem::AddLaserCannons(int _laserCannons) {
    laserCannons += _laserCannons;

    // Laser cannons cannot go higher than the laser cannon capacity
    laserCannons = min(laserCannons, MAXIMUM_LASER_CANNONS);
}

// Generates a report printing the number of laser cannons and the number of torpedoes.
void WeaponsSystem::GenerateReport() {
    // Make cout print floats/doubles with a fixed number of decimals.
    cout.setf(ios::fixed);
    // Sets the number to 2.
    cout.precision(2);
    cout << "Weapon: number of laser cannons:" << laserCannons << ", number of torpedoes:" << torpedoes << "." << endl;
}
