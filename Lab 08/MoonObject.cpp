#include "MoonObject.h"

MoonObject::MoonObject()
{
    initial_height = 0.0;
    initial_vertical_speed = 0.0;
    horizontal_speed = 0.0;
}

MoonObject::MoonObject(double _initial_height, double _initial_vertical_speed, double _horizontal_speed)
{
    initial_height = _initial_height;
    initial_vertical_speed = _initial_vertical_speed;
    horizontal_speed = _horizontal_speed;
}

bool MoonObject::setInitialHeight(double _initial_height)
{
    bool retVal = true;
    if (_initial_height > 0)
        initial_height = _initial_height;
    else
        retVal = false;
    return retVal;
}

bool MoonObject::setInitialVerticalSpeed(double _initial_vertical_speed)
{
    bool retVal = true;
    if (_initial_vertical_speed > 0)
        initial_vertical_speed = _initial_vertical_speed;
    else
        retVal = false;
    return retVal;
}

bool MoonObject::setHorizontalSpeed(double _horizontal_speed)
{
    bool retVal = true;
    if (_horizontal_speed > 0)
        horizontal_speed = _horizontal_speed;
    else
        retVal = false;
    return retVal;
}

double MoonObject::getXPos(double time)
{
    x = horizontal_speed * time;
    return x;
}

double MoonObject::getYPos(double time)
{
    y = initial_height + initial_vertical_speed * time - 0.5 * GAC * time * time;
    return y;
}
