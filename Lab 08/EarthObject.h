#include <iostream>

class EarthObject
{
    const double GAC = 9.81;
    double initial_height;
    double horizontal_speed;
    double x, y;

public:
    EarthObject();
    EarthObject(double, double);
    bool setInitialHeight(double);
    bool setHorizontalSpeed(double);
    double getXPos(double);
    double getYPos(double);
};
