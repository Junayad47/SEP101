#include <iostream>

class MoonObject
{
    const double GAC = 1.625;
    double initial_height;
    double initial_vertical_speed;
    double horizontal_speed;
    double x, y;

public:
    MoonObject();
    MoonObject(double, double, double);
    bool setInitialHeight(double);
    bool setInitialVerticalSpeed(double);
    bool setHorizontalSpeed(double);
    double getXPos(double);
    double getYPos(double);
};
