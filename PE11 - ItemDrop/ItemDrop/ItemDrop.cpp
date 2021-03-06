//Nathan Terrell
//Section 1

#include "stdafx.h"
#include <vector>
#include "Bread.h"
#include "Fruit.h"
#include "Soup.h"
#include "Chocolate.h"

int main()
{
	vector<Item*> inventory;
	inventory.push_back(new Bread());
	inventory.push_back(new Fruit());
	inventory.push_back(new Soup());
	inventory.push_back(new Chocolate());
	for(Item* item : inventory) {
		item->print();
	}
	inventory.clear();
    return 0;
}

