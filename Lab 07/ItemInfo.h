// ItemInfo.h - class declaration for an Item

#include <iostream> //the input/output stream library of C++

// using namespace std;//never put using namespace anything inside a header file. The header file might be included
// by many other files which may not wish to use the namespace.

class ItemInfo
{ // variables and functions are private by default with classes
private:
	std::string name;	   // the string data type is basically a character array. It has many features
	long long int barcode; // that make char arrays easy to use.
	double price;
	bool taxable;

public:
	// getter functions
	std::string GetName() const;
	long long int GetBarcode() const;
	double GetItemPrice() const;
	bool IsTaxable() const;

	// the following functions protect our class variables. They perform validation before
	// the class variables are set.
	// setter functions
	bool SetName(std::string _name); // SetName tests _name against an empty string
	bool SetBarcode(long long _barcode);
	bool SetPrice(double _price);
	bool SetTaxable(bool _taxable);
};