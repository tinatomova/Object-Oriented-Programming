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

#include "MagicCard.hpp"

MagicCard::MagicCard():Card()
{
	type = DEFAULT;
}

MagicCard::MagicCard(std::string n, std::string e, Type t):Card(n,e)
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
		type = rhs.type;
	}
	return *this;
}

Type MagicCard::getType() const
{
	return type;
}

void MagicCard::setType(Type t)
{
	type = t;
}

void MagicCard::print(std::ostream& out) const
{
	out << name << "|" << effect << "|" << getType() << '\n';
}

void MagicCard::set(std::istream& in)
{
	std::string line, n, e, t;
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
	raz = i;
	for (; line[i] != ' '; i++) {
		t[i - raz] = line[i];
		if (isletter(line[i]) == 0)break;
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
