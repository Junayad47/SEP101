// Resistor.cpp - function definitions of the resistor

#include "Resistor.h"

Resistor::Resistor(double resistance) {
    this->resistance = resistance;
}

double Resistor::GetCurrent(double voltage) {
    return voltage / resistance;
}
