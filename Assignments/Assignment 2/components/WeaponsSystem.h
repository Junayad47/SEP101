// WeaponsSystem.h - class declaration for a weapons system

#ifndef _WEAPONSSYSTEM_H_
#define _WEAPONSSYSTEM_H_

#include <iostream>

class WeaponsSystem {
    // Fixed static constant variables.
    static constexpr int TORPEDO_CAPACITY = 100;
    static constexpr int MAXIMUM_LASER_CANNONS = 8;
    static constexpr double ENERGY_PER_SECOND = 1000000000000.0;

    int torpedoes;
    int laserCannons;

   public:
    WeaponsSystem();
    WeaponsSystem(int _torpedoes, int _laserCannons);

    bool FireTorpedo(int _torpedoes);
    double FireLaser(double time);
    void AddTorpedoes(int _torpedoes);
    void AddLaserCannons(int _laserCannons);

    void GenerateReport();
};

#endif
