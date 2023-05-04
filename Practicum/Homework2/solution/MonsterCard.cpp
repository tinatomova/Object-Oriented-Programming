/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler GCC
*/

#include "MonsterCard.hpp"

MonsterCard::MonsterCard():Card()
{
	attackingPoints = 0;
	protectingPoints = 0;
}

MonsterCard::MonsterCard(std::string n, std::string e, unsigned int a, unsigned int p):Card(n,e)
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
	out << name << "|" << effect << "|" << attackingPoints << "|" << protectingPoints << '\n';
}

void MonsterCard::set(std::istream& in)
{
	std::string line, n, e;
	int a = 0, p = 0;
	getline(in, line);
	int i = 0;
	for (; line[i] != '|'; i++) {
		n[i] = line[i];

	}
	i += 2;
	int raz = i;
	setName(n);
	for (; line[i] != '|'; i++) {
		e[i - raz] = line[i];
	}
	setEffect(e);
	i += 2;

	for (; line[i] != '|'; i++) {
		a += line[i] - '0';
		a *= 10;
	}
	a /= 10;
	setAPoints(a);
	i += 2;
	for (; line[i] != ' '; i++) {
		p += line[i] - '0';
		p *= 10;
		if (line[i] < 48 || line[i]>57)break;
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
