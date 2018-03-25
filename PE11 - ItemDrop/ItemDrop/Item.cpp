#include "stdafx.h"
#include <iostream>
#include "Item.h"

Item::Item()
{
}

Item::Item(string itemName, string description, float rare, int amount)
{
	name = itemName;
	desc = description;
	rarity = rare;
	quantity = amount;
}

Item::~Item()
{
}

void Item::print()
{
	cout << name << ":" << endl;
	cout << desc << endl;
	cout << "Rarity: " << rarity << "/10" << endl;
	cout << "There are " << quantity << " of this item." << endl << endl;
}
