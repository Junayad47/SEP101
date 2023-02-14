
// Junayad Bin Forhad
// Student ID: 160158218
// Lab- 01
// Date Created: 23/01/22

#include <stdio.h>

int main()
{
  // PART 1

  float price1, price2, price3, total; // Declaring the type of 3 prices and total.

  printf("Cash Register\n\n");

  printf("Enter the cost of item 1: $");
  scanf("%f", &price1);

  printf("Enter the cost of item 2: $");
  scanf("%f", &price2);

  printf("Enter the cost of item 3: $");
  scanf("%f", &price3);

  total = price1 + price2 + price3;

  printf("\nThe total cost is $%.2f\n\n", total); //%.2f to show only 2 decimals.

  // PART 2
  int pennies = (int)(total * 100); // Used int to get rid of decimals
  int dollars, quarters, dimes, nickels;

  dollars = pennies / 100; // Declared values of various coins, doller and to make the convertion.
  pennies = pennies % 100; // Used modulus to take decimals to next coin convertion.
  quarters = pennies / 25;
  pennies = pennies % 25;
  dimes = pennies / 10;
  pennies = pennies % 10;
  nickels = pennies / 5;
  pennies = pennies % 5;

  printf("You used %d dollars, %d quarters, %d dimes, %d nickels and %d pennies.\n", dollars, quarters, dimes, nickels, pennies);
  return 0;
}
