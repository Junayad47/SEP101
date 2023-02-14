// Main file code for reading database, calling functions and outputs

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define NUM 5
#include "RealEstateCompany.h"

int main(void)
{
	// initialising company variables to 0
	struct Company company = {0};
	// Retrieve data for apartments
	FILE *fp = fopen("Apartments.txt", "r");
	for (int i = 0; i < NUM; ++i)
	{
		fscanf(fp, "%[^\n]s", company.apartment[i].address);
		fscanf(fp, "%d", &company.apartment[i].rooms);
		fscanf(fp, "%d", &company.apartment[i].bathrooms);
		fscanf(fp, "%lf", &company.apartment[i].purchasePrice);
		fscanf(fp, "%lf", &company.apartment[i].monthlyRent);
		fscanf(fp, "%lf", &company.apartment[i].monthlyCondoFees);
		while (fgetc(fp) != '\n')
			; // clear the file buffer before the next fscanf()
	}
	fclose(fp);

	// Retrieve data for townhouses
	fp = fopen("Townhouses.txt", "r");
	for (int i = 0; i < NUM; ++i)
	{
		fscanf(fp, "%[^\n]s", company.townhouse[i].address);
		fscanf(fp, "%d", &company.townhouse[i].rooms);
		fscanf(fp, "%d", &company.townhouse[i].bathrooms);
		fscanf(fp, "%lf", &company.townhouse[i].purchasePrice);
		fscanf(fp, "%lf", &company.townhouse[i].monthlyRent);
		fscanf(fp, "%lf", &company.townhouse[i].monthlyUtilities);
		fscanf(fp, "%lf", &company.townhouse[i].monthlyCondoFees);
		fscanf(fp, "%lf", &company.townhouse[i].monthlyPropertyTax);
		while (fgetc(fp) != '\n')
			; // clear the file buffer before the next fscanf()
	}
	fclose(fp);

	// Retrieve data for semi-detached houses
	fp = fopen("SemiDetachedHouses.txt", "r");
	for (int i = 0; i < NUM; ++i)
	{
		fscanf(fp, "%[^\n]s", company.semihouse[i].address);
		fscanf(fp, "%d", &company.semihouse[i].rooms);
		fscanf(fp, "%d", &company.semihouse[i].bathrooms);
		fscanf(fp, "%lf", &company.semihouse[i].purchasePrice);
		fscanf(fp, "%lf", &company.semihouse[i].monthlyRent);
		fscanf(fp, "%lf", &company.semihouse[i].monthlyUtilities);
		fscanf(fp, "%lf", &company.semihouse[i].monthlyPropertyTax);
		while (fgetc(fp) != '\n')
			; // clear the file buffer before the next fscanf()
	}
	fclose(fp);

	// Accepting Name of the company
	printf("Enter the name of the company: ");
	scanf("%[^\n]s", company.name);
	while (getchar() != '\n')
		; // clear input buffer
	// Accepting the company address
	printf("Enter the address: ");
	scanf("%[^\n]s", company.address);
	// Loop runs for 5 apartments, 5 townhouses and 5 semidetached houses
	for (int i = 0; i < NUM; i++)
	{
		// apartment functions are called
		AptCalEarnings(&company.apartment[i]);
		AptCalReturn(&company.apartment[i]);
		AptCalValue(&company.apartment[i]);
		AptCalGains(&company.apartment[i]);
		// townhouse functions are called
		ThCalEarnings(&company.townhouse[i]);
		ThCalReturn(&company.townhouse[i]);
		ThCalValue(&company.townhouse[i]);
		ThCalGains(&company.townhouse[i]);
		// semi detached house functions are called
		SemCalEarnings(&company.semihouse[i]);
		SemCalReturn(&company.semihouse[i]);
		SemCalValue(&company.semihouse[i]);
		SemCalGains(&company.semihouse[i]);
	}
	// Real estate company functions are called
	AptPerformance(&company);
	ThPerformance(&company);
	SemPerformance(&company);
	// Prints the required output
	printf("The following are financial stats for %s, %s.\n\n", company.name, company.address);
	printf("For the apartments, the monthly earnings are $%.2lf, the roi is %.2lf%%,\n the total value is $%.2lf and the capital gains are $%.2lf\n\n",
		   company.earnings[0], company.returns[0], company.value[0], company.gains[0]);
	printf("For the townhouses, the monthly earnings are $%.2lf, the roi is %.2lf%%,\n the total value is $%.2lf and the capital gains are $%.2lf\n\n",
		   company.earnings[1], company.returns[1], company.value[1], company.gains[1]);
	printf("For the semidetached houses, the monthly earnings are $%.2lf, the roi is %.2lf%%,\n the total value is $%.2lf and the capital gains are $%.2lf\n\n",
		   company.earnings[2], company.returns[2], company.value[2], company.gains[2]);
	return 0;
}