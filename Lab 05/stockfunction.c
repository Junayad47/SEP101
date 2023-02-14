#include <stdio.h>
#include <string.h>

#include "stockheader.h"

void utilClearInputBuffer()
{
    char c;
    do
    {
        c = getchar();
    } while (c != '\n');
}

void calculateYield(struct Company *company)
{
    company->yield = 100 * (company->dividened_year / company->share_price);
}

void calculateValuation(struct Company *company)
{
    const double THRESHOLD = 5.0;

    if (company->yield < THRESHOLD)
    {
        strcpy(company->valuation, "Over Valued");
    }
    else if (company->yield > THRESHOLD)
    {
        strcpy(company->valuation, "Under Valued");
    }
    else
    {
        strcpy(company->valuation, "Fully Valued");
    }
}