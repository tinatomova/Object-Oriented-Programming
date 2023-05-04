#pragma once
#include <vector>
#include <string>
#include <utility>
#include <iostream>
using namespace std;
enum WeaponType
{
	onehanded, twohanded, notype
};
enum WeaponKind
{
	axe, sword, dagger, mace, staff, nokind
};
class Weapon
{
private:
	WeaponType type;
	WeaponKind kind;
	int hitdamage[2];
	vector<pair<string,int>> effect;
	
	double WeaponScore;
	
public:
	WeaponType getType();
	WeaponKind getKind();
	int getMinHitdamage();
	int getMaxHitdamage();
	double getWeaponScore();
	int slots;
	Weapon();
	Weapon(const Weapon& w);
	void setKind(WeaponKind k);
	void setType(WeaponType t);
	void addEffect(pair<string, int> e);
	void removeEffect(string n);
	void changePower(string n, int newP);
	void numberofslots();
	void setHitDamage();
	void setWeaponScore();

	bool operator>(const Weapon&)const;
	bool operator<(const Weapon&)const;
	Weapon& operator=(const Weapon& w);
	friend ostream& operator<<(ostream& os, const Weapon& w);

	//void print();
	

};

ostream& operator<<(ostream& os, const Weapon& w)
{
	os << w.WeaponScore;
	return os;
}