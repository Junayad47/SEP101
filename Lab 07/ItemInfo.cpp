// PetInfo.cpp - function definitions for the pet

#include "ItemInfo.h"

std::string ItemInfo::GetName() const
{
	return name;
}

long long int ItemInfo::GetBarcode() const
{
	return barcode;
}

double ItemInfo::GetItemPrice() const
{
	return price;
}

bool ItemInfo::IsTaxable() const
{
	return taxable;
}

// The validation functions
bool ItemInfo::SetName(std::string _name)
{
	bool retVal = true;
	if (_name.size() == 0)
		retVal = false;
	else
		name = _name; // note, that for char arrays, you had to use strcpy(..)
					  // for string's, you can simply assign one to another
	return retVal;
}

bool ItemInfo::SetPrice(double _price)
{
	bool retVal = true;
	if (_price < 0)
		retVal = false;
	else
		price = _price;
	return retVal;
}

bool ItemInfo::SetBarcode(long long int _barcode)
{
	bool retVal = true;
	if (_barcode > 9999999)
		retVal = false;
	else
		barcode = _barcode;
	return retVal;
}

bool ItemInfo::SetTaxable(bool _taxable)
{
	taxable = _taxable;
	return true;
}