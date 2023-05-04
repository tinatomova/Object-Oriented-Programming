#pragma once
#include <iostream>
#include<utility>
#include<vector>
#include<string>
using namespace std;
enum ArmorType
{
	cloth,
	leather,
	mail,
	DEFAULT
};

class Armor
{private:
	int slots = 1;
	ArmorType type;
	vector<pair<string, int>> effect;
	int defense;
	int GearScore;
public:
	Armor();
	Armor(const Armor& A);
	ArmorType getType();
	int getDefense();
	int getGearScore();
	void setType(ArmorType t);
	void setDefence(int);
	void addEffect(pair<string, int> e);
	void removeEffect(string n);
	void changePower(string n, int newP);
	void setGearScore();

	bool operator>(const Armor&)const;
	bool operator<(const Armor&)const;
	Armor& operator=(const Armor& A);
	friend ostream& operator<<(ostream& os, const Armor& A);

	void print();

	
};
ostream& operator<<(ostream& os, const Armor& A)
{
	os << A.GearScore;
	return os;
}