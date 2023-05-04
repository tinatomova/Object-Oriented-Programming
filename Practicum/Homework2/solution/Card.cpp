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

#include "Card.hpp"

Card::Card()
{
	name="";
	effect="";
}

Card::Card(std::string n, std::string e)
{
	name = n;
	effect = e;
}

Card::Card(const Card& c)
{
	name = c.name;
	effect = c.effect;
}

void Card::setName(std::string n)
{
	name = n;
}

void Card::setEffect(std::string e)
{
	effect = e;
}

std::string Card::getName()const
{
	return name;
}

std::string Card::getEffect() const
{
	return effect;
}

Card& Card::operator=(const Card& rhs)
{
	if (this != &rhs) {
		name = rhs.name;
		effect = rhs.effect;
	}
	return *this;
}

void Card::print(std::ostream& out) const
{
	out << getName() << '|' << getEffect() << '\n';
}

void Card::set(std::istream& in)
{
	std::string line, n, e;
	in >> line;
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
