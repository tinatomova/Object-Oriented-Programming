#include "Weapon.hpp"


WeaponType Weapon::getType()
{
	return type;
}

WeaponKind Weapon::getKind()
{
	return kind;
}

int Weapon::getMinHitdamage()
{
	return hitdamage[0];
}

int Weapon::getMaxHitdamage()
{
	return hitdamage[1];
}

double Weapon::getWeaponScore()
{
	return WeaponScore;
}

Weapon::Weapon()
{
	type = notype;
	kind = nokind;
	hitdamage[0] = 0;
	hitdamage[1] = 0;
	effect = {};
	slots = 0;
	WeaponScore = 0;

}

Weapon::Weapon(const Weapon& w)
{
	type = w.type;
	kind = w.kind;
	hitdamage[0] = w.hitdamage[0];
	hitdamage[1] = w.hitdamage[1];
	effect = w.effect;
	slots = w.slots;
	WeaponScore = w.WeaponScore;
}

void Weapon::setKind(WeaponKind k)
{
	kind = k;
	if (k == staff)type = twohanded;
	if (k == dagger)type = onehanded;
	numberofslots();
	setHitDamage();
	setWeaponScore();
}

void Weapon::setType(WeaponType t)
{
	if (kind == dagger && t == twohanded)return;
	else if (kind == staff && t == onehanded)return;
	type = t;
	numberofslots();
	setHitDamage();
	setWeaponScore();
}

void Weapon::addEffect(pair<string,int> e)
{
	for (unsigned int i = 0; i < effect.size(); i++) {
		if (e.first == effect.at(i).first)return;
	}
	effect.push_back(e);
	numberofslots();
	setHitDamage();
	setWeaponScore();
}

void Weapon::removeEffect(string n)
{
	for (unsigned int i = 0; i < effect.size(); i++) {
		if (effect.at(i).first == n) {
			effect.erase(effect.begin() + i);
			
		}
	}
	numberofslots();
	setHitDamage();
	setWeaponScore();
}

void Weapon::changePower(string n, int newP)
{
	for (unsigned int i = 0; i < effect.size(); i++) {
		if (effect.at(i).first == n) {
			effect.at(i).second=newP;
			
		}
	}
	numberofslots();
	setHitDamage();
	setWeaponScore();
}

void Weapon::numberofslots()
{
	if (type == onehanded)slots = 1;
	if (type == twohanded)slots = 2;
}

void Weapon::setHitDamage()
{
	if(effect.size()>0){
		int min = effect.at(0).second;
		int max = effect.at(0).second;
		for (unsigned int i = 0; i < effect.size(); i++) {
			if (min > effect.at(i).second) min = effect.at(i).second;
			if (max < effect.at(i).second) max = effect.at(i).second;
		}
		hitdamage[0] = min;
		hitdamage[1] = max;
	}
	
}

void Weapon::setWeaponScore()
{
	double score = (hitdamage[0]+hitdamage[1])/2;
	for (unsigned int i = 0; i < effect.size(); i++) {
		score += effect.at(i).second;
	}
	WeaponScore = score * slots * 0.75;
}

bool Weapon::operator>(const Weapon& rhs) const
{
	return WeaponScore>rhs.WeaponScore;
}

bool Weapon::operator<(const Weapon& rhs) const
{
	return WeaponScore<rhs.WeaponScore;
}

Weapon& Weapon::operator=(const Weapon& w)
{
	type = w.type;
	kind = w.kind;
	hitdamage[0] = w.hitdamage[0];
	hitdamage[1] = w.hitdamage[1];
	effect = w.effect;
	slots = w.slots;
	WeaponScore = w.WeaponScore;
	return *this;
	
}

/*void Weapon::print()
{
	cout << "type: " << type << "; slots: " << slots << "; kind: " << kind << "; WeaponScore: " << WeaponScore << endl;
	cout << "min hitdamage: " << hitdamage[0] << "; max hitdamage: " << hitdamage[1] << endl;
	if (effect.size() > 0) {
		for (unsigned int i = 0; i < effect.size(); i++) {
			cout << "effect" << i << ": " << effect.at(i).first << " - " << effect.at(i).second << endl;
		}
	}
}
*/
