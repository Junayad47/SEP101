//.c file code for function definitions

#include <stdio.h>
#include "Apartment.h"
#include "Townhouse.h"
#include "SemiDetachedHouse.h"
#include "RealEstateCompany.h"
#define _CRT_SECURE_NO_WARNINGS
#define interestRate 0.05 // contsant

// APARTMENTS:
void AptCalEarnings(struct Apartment *apartment)
{
	// claculating monthly earnings for each apartment
	apartment->monthlyEarnings = apartment->monthlyRent - apartment->monthlyCondoFees;
}
void AptCalReturn(struct Apartment *apartment)
{
	// claculating annual return for each apartment
	apartment->annualReturn = 100.0 * 12.0 * apartment->monthlyEarnings / apartment->purchasePrice;
}
void AptCalValue(struct Apartment *apartment)
{
	// claculating current value for each apartment
	apartment->currentValue = 12.0 * apartment->monthlyEarnings / interestRate;
}
void AptCalGains(struct Apartment *apartment)
{
	// claculating capital gains for each apartment
	apartment->capitalGains = apartment->currentValue - apartment->purchasePrice;
}

// TOWN HOUSES:
void ThCalEarnings(struct Townhouse *townhouse)
{
	// claculating monthly earnings for each townhouse
	townhouse->monthlyEarnings = townhouse->monthlyRent - townhouse->monthlyUtilities - townhouse->monthlyCondoFees - townhouse->monthlyPropertyTax;
}
void ThCalReturn(struct Townhouse *townhouse)
{
	// claculating annual return for each townhouse
	townhouse->annualReturn = 100.0 * 12.0 * townhouse->monthlyEarnings / townhouse->purchasePrice;
}
void ThCalValue(struct Townhouse *townhouse)
{
	// claculating current value for each townhouse
	townhouse->currentValue = 12.0 * townhouse->monthlyEarnings / interestRate;
}
void ThCalGains(struct Townhouse *townhouse)
{
	// claculating capital gains for each townhouse
	townhouse->capitalGains = townhouse->currentValue - townhouse->purchasePrice;
}

// SEMI DETACHED HOUSES:
void SemCalEarnings(struct SemiHouse *semihouse)
{
	// claculating monthly earnings for each semi detached house
	semihouse->monthlyEarnings = semihouse->monthlyRent - semihouse->monthlyUtilities - semihouse->monthlyPropertyTax;
}

void SemCalReturn(struct SemiHouse *semihouse)
{
	// claculating annual return for each semi detached house
	semihouse->annualReturn = 100.0 * 12.0 * semihouse->monthlyEarnings / semihouse->purchasePrice;
}

void SemCalValue(struct SemiHouse *semihouse)
{
	// claculating current value for each semi detached house
	semihouse->currentValue = 12.0 * semihouse->monthlyEarnings / interestRate;
}

void SemCalGains(struct SemiHouse *semihouse)
{
	// claculating capital gains for each semi detached house
	semihouse->capitalGains = semihouse->currentValue - semihouse->purchasePrice;
}

// REAL ESTATE COMPANY:
void AptPerformance(struct Company *company)
{
	// calculating performance for 5 apartments
	// running totals:
	company->earnings[0] = 0;
	company->returns[0] = 0;
	company->value[0] = 0;
	company->gains[0] = 0;
	for (int i = 0; i < NUM; i++)
	{
		// adding respective values
		company->earnings[0] = company->earnings[0] + company->apartment[i].monthlyEarnings;
		company->returns[0] = company->returns[0] + company->apartment[i].annualReturn;
		company->value[0] = company->value[0] + company->apartment[i].currentValue;
		company->gains[0] = company->gains[0] + company->apartment[i].capitalGains;
	}
	// final return is always divided by number of apartments for percentage ratio
	company->returns[0] = company->returns[0] / 5.0;
}

void ThPerformance(struct Company *company)
{
	// calculating performance for 5 townhouses
	// running totals:
	company->earnings[1] = 0;
	company->returns[1] = 0;
	company->value[1] = 0;
	company->gains[1] = 0;
	for (int i = 0; i < NUM; i++)
	{
		// adding respective values
		company->earnings[1] = company->earnings[1] + company->townhouse[i].monthlyEarnings;
		company->returns[1] = company->returns[1] + company->townhouse[i].annualReturn;
		company->value[1] = company->value[1] + company->townhouse[i].currentValue;
		company->gains[1] = company->gains[1] + company->townhouse[i].capitalGains;
	}
	// final return is always divided by number of townhouses for percentage ratio
	company->returns[1] = company->returns[1] / 5.0;
}

void SemPerformance(struct Company *company)
{
	// calculating performance for 5 semi detached houses
	// running totals:
	company->earnings[2] = 0;
	company->returns[2] = 0;
	company->value[2] = 0;
	company->gains[2] = 0;
	for (int i = 0; i < NUM; i++)
	{
		// adding respective values
		company->earnings[2] = company->earnings[2] + company->semihouse[i].monthlyEarnings;
		company->returns[2] = company->returns[2] + company->semihouse[i].annualReturn;
		company->value[2] = company->value[2] + company->semihouse[i].currentValue;
		company->gains[2] = company->gains[2] + company->semihouse[i].capitalGains;
	}
	// final return is always divided by number of semi detached houses for percentage ratio
	company->returns[2] = company->returns[2] / 5.0;
}
