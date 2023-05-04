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

#include "MagicCard.hpp"

MagicCard::MagicCard() :Card()
{
	type = DEFAULT;
}

MagicCard::MagicCard(std::string n, std::string e,unsigned int r, Type t) : Card(n, e, r)
{
	type = t;
}

MagicCard::MagicCard(const MagicCard& magic) : Card(magic)
{
	type = magic.type;
}

MagicCard& MagicCard::operator=(const MagicCard& rhs)
{
	if (this != &rhs) {

		name = rhs.name;
		effect = rhs.effect;
		rarity = rhs.rarity;
		type = rhs.type;
	}
	return *this;
}

std::string MagicCard::getType() const
{
	std::string str = "";
	if (type == trap)str = "trap";
	if (type == buff)str = "buff";
	if (type == spell)str = "spell";
	return str;
}

void MagicCard::setType(Type t)
{
	type = t;
}

void MagicCard::print(std::ostream& out) const
{
	out << name << "|" << effect << "|" << rarity << "|" << getType() << '\n';
}

void MagicCard::set(std::istream& in)
{
	std::string line, n="", e="", t="";
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
	for (; isletter(line[i]) != 0; i++) {
		t += line[i];
		
	}
	if (t == "trap")setType(trap);
	if (t == "buff")setType(buff);
	if (t == "spell")setType(spell);
}

/*std::ostream& operator<<(std::ostream& out, const MagicCard& magic)
{
	magic.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, MagicCard& magic)
{

	magic.set(in);
	return in;

}*/

bool isletter(char a)
{
	if (a >= 'a' && a <= 'z')return true;
	if (a >= 'A' && a <= 'Z')return true;
	return false;
}