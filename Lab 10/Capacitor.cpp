// Capacitor.cpp - function definitions of the capacitor

#include "Capacitor.h"

Capacitor::Capacitor(double capacitance) {
    this->capacitance = capacitance;
    this->voltage = 0;
}

double Capacitor::GetCurrent(double voltage, double delta) {
    double current = capacitance * (voltage - this->voltage) / delta;
    this->voltage = voltage;
    return current;
}
