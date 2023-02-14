// Townhouse Header File

#ifndef _TOWNHOUSE_H_
#define _TOWNHOUSE_H_
#define SIZE 255
struct Townhouse
{
	// Required variabled for Townhouses
	char address[SIZE];
	int rooms;
	int bathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyCondoFees;
	double monthlyPropertyTax;
	// Calculations
	double monthlyEarnings;
	double annualReturn;
	double currentValue;
	double capitalGains;
};

// All calculations under townhouse- pass by address
void ThCalEarnings(struct Townhouse *townhouse);
void ThCalReturn(struct Townhouse *townhouse);
void ThCalValue(struct Townhouse *townhouse);
void ThCalGains(struct Townhouse *townhouse);

#endif