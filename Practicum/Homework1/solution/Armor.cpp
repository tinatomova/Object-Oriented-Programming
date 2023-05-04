#include "Armor.hpp"

Armor::Armor()
{
	type = DEFAULT;
	effect = {};
	defense = 0;
	GearScore = 0;
}

Armor::Armor(const Armor& A)
{
	slots = 1;
	type = A.type;
	effect = A.effect;
	defense = A.defense;
	GearScore = A.GearScore;
}

ArmorType Armor::getType()
{
	return type;
}

int Armor::getDefense()
{
	return defense;
}

int Armor::getGearScore()
{
	return GearScore;
}

void Armor::setType(ArmorType t)
{
	type = t;
}

void Armor::setDefence(int d)
{
	defense = d;
}

void Armor::addEffect(pair<string, int> e)
{
	for (unsigned int i = 0; i < effect.size(); i++) {
		if (e.first == effect.at(i).first)return;
	}
	effect.push_back(e);
	setGearScore();
}

void Armor::removeEffect(string n)
{
	for (unsigned int i = 0; i < effect.size(); i++) {
		if (effect.at(i).first == n) {
			effect.erase(effect.begin() + i);

		}
	}
	setGearScore();
}

void Armor::changePower(string n, int newP)
{
	for (unsigned int i = 0; i < effect.size(); i++) {
		if (effect.at(i).first == n) {
			effect.at(i).second = newP;

		}
	}
	setGearScore();
}

void Armor::setGearScore()
{
	GearScore = 0;
	if (effect.size() > 0) {
		for (unsigned int i = 0; i < effect.size(); i++) {
			GearScore += effect.at(i).second;
		}
	}
}

bool Armor::operator>(const Armor& rhs) const
{
	return GearScore > rhs.GearScore;
}

bool Armor::operator<(const Armor& rhs) const
{
	return GearScore < rhs.GearScore;
}

Armor& Armor::operator=(const Armor& A)
{
	type = A.type;
	effect = A.effect;
	slots = A.slots;
	GearScore = A.GearScore;
	return *this;
}

void Armor::print()
{
	cout << "type: " << type << "; slots: " << slots << "; defence: " << defense << "; GearScore: " << GearScore << endl;
	if (effect.size() > 0) {
		for (unsigned int i = 0; i < effect.size(); i++) {
			cout << "effect" << i << ": " << effect.at(i).first << " - " << effect.at(i).second << endl;
		}
	}
}

