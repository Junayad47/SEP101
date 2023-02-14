// Semi Detached House Header File

#ifndef _SEMIDETACHEDHOUSE_H_
#define _SEMIDETACHEDHOUSE_H_
#define SIZE 255
struct SemiHouse
{
	// Required variables for Semi detached houses
	char address[SIZE];
	int rooms;
	int bathrooms;
	double purchasePrice;
	double monthlyRent;
	double monthlyUtilities;
	double monthlyPropertyTax;
	// Calulations
	double monthlyEarnings;
	double annualReturn;
	double currentValue;
	double capitalGains;
};

// All calculations under Semi-Detached house - pass by address
void SemCalEarnings(struct SemiHouse *semihouse);
void SemCalReturn(struct SemiHouse *semihouse);
void SemCalValue(struct SemiHouse *semihouse);
void SemCalGains(struct SemiHouse *semihouse);
#endif
