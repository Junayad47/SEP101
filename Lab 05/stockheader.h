#include <stdio.h>

#define MAX_STR 32
#define TOTAL_COMPANIES 5

struct Company
{
    char company_name[MAX_STR];
    char company_symbol[MAX_STR];
    char valuation[MAX_STR];
    double share_price;
    double dividened_year;
    double yield;
};

void utilClearInputBuffer(void);
void calculateYield(struct Company *company);
void calculateValuation(struct Company *company);
