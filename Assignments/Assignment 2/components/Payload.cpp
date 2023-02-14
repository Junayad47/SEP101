// Payload.cpp - function definitions for a payload

#include "Payload.h"

using namespace std;

// Payload constructor with default parameters (all set to 0.0)
Payload::Payload() {
    passengers = 0.0;
    cargo = 0.0;
    workstations = 0.0;
}

// Payload constructor with mass of passengers, cargo and workstations respectively
Payload::Payload(double _passengers, double _cargo, double _workstations) {
    passengers = _passengers;
    cargo = _cargo;
    workstations = _workstations;
}

// Returns the total mass
double Payload::GetMass() {
    return passengers + cargo + workstations;
}

// Adds new passengers mass to the existing passengers mass
void Payload::AddPassengers(double _passengers) {
    passengers += _passengers;
}

// Adds new cargo mass to the existing cargo mass.
void Payload::AddCargo(double _cargo) {
    cargo += _cargo;
}

// Adds new workstations mass to the existing workstations mass.
void Payload::AddWorkstations(double _workstations) {
    workstations += _workstations;
}

// Generates a report that prints the mass of the passengers, cargo, and workstations.
void Payload::GenerateReport() {
    // Make cout print floats/doubles with a fixed number of decimals.
    cout.setf(ios::fixed);
    // Sets the number to 2.
    cout.precision(2);
    cout << "Payload: mass of passengers:" << passengers << "kg, mass of cargo:" << cargo << "kg, mass of workstations:" << workstations << "kg." << endl;
}
