// Apartment Header File

#ifndef _APARTMENT_H_
#define _APARTMENT_H_
#define SIZE 255
struct Apartment
{
	// Required variables for apartments
	char address[SIZE];
	int rooms;
	int bathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyCondoFees;
	// Calculations
	double monthlyEarnings;
	double annualReturn;
	double currentValue;
	double capitalGains;
};

// All calculations under apartment - pass by address
void AptCalEarnings(struct Apartment *apartment);
void AptCalReturn(struct Apartment *apartment);
void AptCalValue(struct Apartment *apartment);
void AptCalGains(struct Apartment *apartment);

#endif
