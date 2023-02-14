#include <stdio.h>

int main()
{
    printf(".....Cash Register.....  \n \n");
    float price1, price2, price3, total;
    printf("Enter the value of first item: $ ");
    scanf("%f", &price1);
    printf("Enter the value of second item: $ ");
    scanf("%f", &price2);
    printf("Enter the value of third item: $ ");
    scanf("%f", &price3);

    total = price1 + price2 + price3;
    printf("Your bill is $ %.2f \n", total);

    int penny = total * 100;
    int doller, quarter, dime, nickel;

    doller = penny / 100;
    penny = penny % 100;
    quarter = penny / 25;
    penny = penny % 25;
    dime = penny / 10;
    penny = penny % 10;
    nickel = penny / 5;
    penny = penny % 5;

    printf("You've spent %d dollers, %d quarters, %d dimes, %d nickels and %d pennies", doller, quarter, dime, nickel, penny);
}
