#pragma once
#include <string>
using namespace std;

struct Item
{
public:
	Item();
	Item(string itemName, string description, float rare, int amount);
	~Item();

	void print();
private:
	string name;
	string desc;
	float rarity;
	int quantity;
};

