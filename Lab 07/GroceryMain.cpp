/*
Lab 7
Junayad Bin forhad
160158218


1. Which members of your class are visible to the outside world and which members are
hidden from the outside world?
Ans: Data type with Private tagged in classes are invisible and public are visible to the outside
world.

2. Why do we use accessor functions to get or set these private members?
Ans: So, the values can't be manipulated and validated before set.

3. Do you see your class as a blackbox or as a whitebox, or as a bit of each?
Ans: As a bit of each.


*/

#include <iomanip> //setw() setprecision()
#include <cstdio>
#include <limits>
#include "ItemInfo.h" //PetInfo.h includes iostream

using namespace std; // use all libraries inside the package std

void clearKeyboard(void)
{
	while (getchar() != '\n')
		;
}

void printSeparator(int n)
{
	while (n--)
	{
		cout << "-";
	}
	cout << endl;
}

int main()
{
	const int NUM = 5;
	ItemInfo items[NUM];
	cout << "Enter the number of items (5 max): ";
	int total;
	cin >> total;
	clearKeyboard();
	for (int i = 0; i < total; i++)
	{
		string name;
		long long int barcode;
		double price;
		bool taxable;

		bool success = false;
		while (!success)
		{
			cout << "Enter the name of the grocery item: ";
			getline(cin, name);
			success = items[i].SetName(name);
			if (!success)
				cout << "Invalid name" << endl;
		}

		success = false;
		while (!success)
		{
			cout << "Enter the barcode of the grocery item (Upto 7 digits): ";
			cin >> barcode;
			clearKeyboard();
			success = items[i].SetBarcode(barcode);
			if (!success)
				cout << "Invalid barcode" << endl;
		}

		success = false;
		while (!success)
		{
			cout << "Enter the cost of the grocery item: $";
			cin >> price;
			clearKeyboard();
			success = items[i].SetPrice(price);
			if (!success)
				cout << "Invalid cost" << endl;
		}

		success = false;
		while (!success)
		{
			char answer;
			cout << "Is the grocery item taxable? [Y/N] ";
			cin >> answer;
			clearKeyboard();
			success = tolower(answer) == 'y' || tolower(answer) == 'n';
			if (success)
				items[i].SetTaxable(tolower(answer) == 'y' ? true : false);
		}
	}

	cout << fixed << setprecision(2);
	cout << endl;

	double subTotal = 0;
	double taxes = 0;

	for (int i = 0; i < total; i++)
	{
		string name = items[i].GetName();
		bool isTaxable = items[i].IsTaxable();
		double price = items[i].GetItemPrice();
		double tax = isTaxable ? price * 0.13 : 0;
		subTotal += price;
		taxes += tax;

		cout << "name: " << left << setw(25) << name << "cost: $" << setw(15) << price << "tax: $" << tax << endl;
	}

	printSeparator(12);

	cout << "Subtotal: "
		 << "$" << subTotal << endl;
	cout << "Taxes: "
		 << "$" << taxes << endl;
	cout << "Total: "
		 << "$" << taxes + subTotal << endl;

	return 0;
}
