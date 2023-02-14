#include "EarthObject.h"

EarthObject::EarthObject()
{
    initial_height = 0.0;
    horizontal_speed = 0.0;
}

EarthObject::EarthObject(double _initial_height, double _horizontal_speed)
{
    initial_height = _initial_height;
    horizontal_speed = _horizontal_speed;
}

bool EarthObject::setInitialHeight(double _initial_height)
{
    bool retVal = true;
    if (_initial_height > 0)
        initial_height = _initial_height;
    else
        retVal = false;
    return retVal;
}

bool EarthObject::setHorizontalSpeed(double _horizontal_speed)
{
    bool retVal = true;
    if (_horizontal_speed > 0)
        horizontal_speed = _horizontal_speed;
    else
        retVal = false;
    return retVal;
}

double EarthObject::getXPos(double time)
{
    x = horizontal_speed * time;
    return x;
}

double EarthObject::getYPos(double time)
{
    y = initial_height - 0.5 * GAC * time * time;
    return y;
}
