// Inductor.cpp - function definitions of the inductor

#include "Inductor.h"

Inductor::Inductor(double inductance) {
    this->inductance = inductance;
    this->current = 0;
}

double Inductor::GetCurrent(double voltage, double delta) {
    current = current + voltage * delta / inductance;
    return current;
}
