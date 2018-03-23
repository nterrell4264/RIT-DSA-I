#include "stdafx.h"
#include "Item.h"
#include <iostream>

Item::Item()
{
}


Item::~Item()
{
}

void Item::print()
{
	cout << "Item " << name << ":" << endl;
	cout << "Rarity: " << rarity << "/10" << endl;
	if(uses >= 0) cout << uses << " uses left." << endl;
	cout << quantity << " of this item in the inventory." << endl;
}
