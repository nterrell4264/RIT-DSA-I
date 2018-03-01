#pragma once
class Player
{
public:
	Player();
	Player(const char* student, int eng, int soc, int mth, int sci);
	~Player();

	void printPlayer();
private:
	const char* name;
	int english;
	int socialStudies;
	int math;
	int science;
};

