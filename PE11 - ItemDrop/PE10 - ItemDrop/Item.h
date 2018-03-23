#pragma once

#include <string>
using namespace std;

struct Item
{
public:
	Item() : name("DUMMY"), rarity(1.0f), uses(-1), quantity(1) {}
	~Item();

	void print();
private:
	string name;
	float rarity;
	int uses;
	int quantity;
};

