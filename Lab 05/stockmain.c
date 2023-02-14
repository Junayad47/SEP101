/*
Name: Junayad Bin Forhad
ID: 160158218
Lab-05

Explain whether a structure was necessary and if so, explain why you composed your
structure as you did.
Ans: A program like this will definately need a structure because we have to store
multiple data types and we don't want to write the same thing over and over.

Explain whether any functions were necessary, and explain why you composed the
functions as you did.
Ans: Functions were absoloutely necessary for calculation and to clear the leftover
input of character strings.

Explain whether any loops were necessary, and why.
Ans: Yes,loops were necessary to have the control over the program and set the amount
of companies.

*/

#include <stdio.h>

#include "stockfunction.c"

int main()
{
    struct Company companies[TOTAL_COMPANIES];

    for (int i = 0; i < TOTAL_COMPANIES; i++)
    {
        printf("Enter the company name: ");
        scanf("%[^\n]s", &companies[i].company_name);
        utilClearInputBuffer();
        printf("Enter %s's stock symbol: ", companies[i].company_name);
        scanf("%[^\n]s", &companies[i].company_symbol);
        utilClearInputBuffer();
        printf("Enter %s's current stock price: ", companies[i].company_name);
        scanf("%lf", &companies[i].share_price);
        utilClearInputBuffer();
        printf("Enter %s's annual dividend per share: ", companies[i].company_name);
        scanf("%lf", &companies[i].dividened_year);
        utilClearInputBuffer();

        calculateYield(&companies[i]);
        calculateValuation(&companies[i]);
    }

    printf("\n\n%25s %8s %4s %7s %7s %14s\n", "COMPANY", "SYMBOL", "PRICE", "DIV", "YIELD", "VALUATION");

    for (int i = 0; i < TOTAL_COMPANIES; i++)
    {
        printf("%25s %8s %4.2lf %7.3lf %7.3lf %14s\n", companies[i].company_name, companies[i].company_symbol, companies[i].share_price, companies[i].dividened_year, companies[i].yield, companies[i].valuation);
    }

    return 0;
}