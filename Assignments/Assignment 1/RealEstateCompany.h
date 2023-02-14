// Real Estate Company Header File

#include "Apartment.h"
#include "Townhouse.h"
#include "SemiDetachedHouse.h"
#define len 32
#define SIZE 255
#define NUM 5
#define type 3
struct Company
{
	// company name and address
	char name[len];
	char address[SIZE];
	// to calculate total of the following:
	double earnings[type];
	double returns[type];
	double value[type];
	double gains[type];
	// struct array for 5 of each:
	struct Apartment apartment[NUM];
	struct Townhouse townhouse[NUM];
	struct SemiHouse semihouse[NUM];
};

// Function prototypes for performance calculations- all pass by address
void AptPerformance(struct Company *company);
void ThPerformance(struct Company *company);
void SemPerformance(struct Company *company);
