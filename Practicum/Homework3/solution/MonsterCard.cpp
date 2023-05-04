/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler VC
*/

#include "MonsterCard.hpp"

MonsterCard::MonsterCard() :Card()
{
	attackingPoints = 0;
	protectingPoints = 0;
}

MonsterCard::MonsterCard(std::string n, std::string e,unsigned int r, unsigned int a, unsigned int p) :Card(n, e, r)
{
	attackingPoints = a;
	protectingPoints = p;
}

MonsterCard::MonsterCard(const MonsterCard& monster) : Card(monster)
{
	attackingPoints = monster.attackingPoints;
	protectingPoints = monster.protectingPoints;
}

MonsterCard& MonsterCard::operator=(const MonsterCard& rhs)
{
	if (this != &rhs) {
		name = rhs.name;
		effect = rhs.effect;
		rarity = rhs.rarity;
		attackingPoints = rhs.attackingPoints;
		protectingPoints = rhs.protectingPoints;
	}
	return *this;
}

unsigned int MonsterCard::getAPoints()const
{
	return attackingPoints;
}

unsigned int MonsterCard::getPPoints()const
{
	return protectingPoints;
}

void MonsterCard::setAPoints(unsigned int a)
{
	attackingPoints = a;
}

void MonsterCard::setPPoints(unsigned int p)
{
	protectingPoints = p;
}

void MonsterCard::print(std::ostream& out)const
{
	out << name << "|" << effect << "|" <<rarity<<'|'<< attackingPoints << "|" << protectingPoints << '\n';
}

void MonsterCard::set(std::istream& in)
{
	std::string line, n="", e="";
	int a = 0, p = 0;
	unsigned int r = 0;
	getline(in, line);
	int i = 0;
	for (; line[i] != '|'; i++) {
		n += line[i];

	}
	i++;
	setName(n);
	for (; line[i] != '|'; i++) {
		e += line[i];
	}
	setEffect(e);
	i++;
	for (; line[i] != '|'; i++) {
		r += line[i]-'0';
		r *= 10;
	}
	r /= 10;
	rarity = r;
	i++;
	for (; line[i] != '|'; i++) {
		a += line[i] - '0';
		a *= 10;
	}
	a /= 10;
	setAPoints(a);
	i++; 
	for (; line[i] >= '0' && line[i] <= '9'; i++) {
		p += line[i] - '0';
		p *= 10;
		
	}
	p /= 10;
	setPPoints(p);
}

/*std::ostream& operator<<(std::ostream& out, const MonsterCard& monster)
{
	monster.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, MonsterCard& monster)
{
	monster.set(in);
	return in;

}
*/