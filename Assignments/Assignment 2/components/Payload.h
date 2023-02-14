// Payload.h - class declaration for a payload

#ifndef _PAYLOAD_H_
#define _PAYLOAD_H_

#include <iostream>

class Payload {
    double passengers;
    double cargo;
    double workstations;

   public:
    Payload();
    Payload(double _passengers, double _cargo, double _workstations);

    double GetMass();

    void AddPassengers(double _passengers);
    void AddCargo(double _cargo);
    void AddWorkstations(double _workstations);

    void GenerateReport();
};

#endif
