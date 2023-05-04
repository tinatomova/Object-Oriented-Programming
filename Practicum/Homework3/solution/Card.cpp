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

#include "Card.hpp"

Card::Card()
{
	name = "";
	effect = "";
	rarity = 0;
}

Card::Card(std::string n, std::string e, unsigned int r)
{
	name = n;
	effect = e;
	rarity = r;
}

Card::Card(const Card& c)
{
	name = c.name;
	effect = c.effect;
	rarity = c.rarity;
}

void Card::setName(std::string n)
{
	name = n;
}

void Card::setEffect(std::string e)
{
	effect = e;
}

void Card::setRarity(unsigned int r)
{
	rarity = r;
}

std::string Card::getName()const
{
	return name;
}

std::string Card::getEffect() const
{
	return effect;
}

unsigned int Card::getRarity() const
{
	return rarity;
}

Card& Card::operator=(const Card& rhs)
{
	if (this != &rhs) {
		name = rhs.name;
		effect = rhs.effect;
	}
	return *this;
}

bool Card::operator<(const Card& rhs) const
{
	if (rarity < rhs.rarity)return true;
	return false;
}

bool Card::operator>(const Card& rhs) const
{
	if (rarity > rhs.rarity)return true;
	return false;
}

void Card::print(std::ostream& out) const
{
	out << getName() << '|' << getEffect() <<'|'<< rarity<<'\n';
}
 Card::~Card(){}

void Card::set(std::istream& in)
{
	std::string line, n = "", e = "";
	unsigned int r=0;
	in >> line;
	int i = 0;
	for (; line[i] != '|'; i++) {
		n += line[i];

	}
	
	i += 1;
	setName(n);
	for (; line[i] != '|'; i++) {
		e += line[i];
	}
	setEffect(e);
	i += 1;
	
	for (; line[i] >='0'&&line[i]<='9'; i++) {
		r += line[i]-'0';
		r *= 10;
	}
	r /= 10;
	rarity = r;
}

std::ostream& operator<<(std::ostream& out, const Card& card)
{
	card.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Card& card)
{
	card.set(in);
	return in;
}