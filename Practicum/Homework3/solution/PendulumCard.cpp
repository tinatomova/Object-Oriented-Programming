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

#include "PendulumCard.hpp"

PendulumCard& PendulumCard::operator=(const PendulumCard& rhs)
{
	if (this != &rhs) {
		MagicCard::operator=(rhs);
		MonsterCard::operator=(rhs);
		scale = rhs.scale;

	}
	return *this;
}

PendulumCard::PendulumCard() : Card(), MonsterCard(), MagicCard()
{
	scale = 1;
}

PendulumCard::PendulumCard(std::string n, std::string e,unsigned int r, unsigned int a, unsigned int p, unsigned int s, Type t) :Card(n,e,r), MonsterCard(n, e, r, a, p), MagicCard(n, e, r, t)
{
	if (s > 0 && s < 14)scale = s;
	else scale = 1;
}
unsigned int PendulumCard::getScale() const
{
	return scale;
}
void PendulumCard::setScale(unsigned int s)
{
	scale = s;
}
void PendulumCard::print(std::ostream& out)const
{
	out << MonsterCard::getName() << "|" << MonsterCard::getEffect() << "|" << MonsterCard::getRarity() << "|" << MonsterCard::getAPoints() << "|" << MonsterCard::getPPoints() << "|" << getScale() << "|" << getType() << '\n';
}
void PendulumCard::set(std::istream& in)
{
	std::string line, n="", e="", t="";
	unsigned int r = 0;
	int a = 0, p = 0, s = 0;
	in >> line;
	int i = 0;
	for (; line[i] != '|'; i++) {
		n += line[i];

	}
	i++;
	MonsterCard::setName(n);
	for (; line[i] != '|'; i++) {
		e += line[i];
	}
	MonsterCard::setEffect(e);
	i++;
	for (; line[i] != '|'; i++) {
		r += line[i]-'0';
		r *= 10;
	}
	r /= 10;
	MonsterCard::setRarity(r);
	i++;

	for (; line[i] != '|'; i++) {
		a += line[i] - '0';
		a *= 10;
	}
	a /= 10;
	setAPoints(a);
	i++;
	for (; line[i] != '|'; i++) {
		p += line[i] - '0';
		p *= 10;
	}
	p /= 10;
	setPPoints(p);
	i++;
	for (; line[i] != '|'; i++) {
		s += line[i] - '0';
		s *= 10;
	}
	s /= 10;
	setScale(s);
	i++;
	for (; isletter(line[i]) != 0; i++) {
		t += line[i];
	}
	if (t == "trap")setType(trap);
	if (t == "buff")setType(buff);
	if (t == "spell")setType(spell);
}
/*std::ostream& operator<<(std::ostream& out, const PendulumCard& pen)
{
	pen.print(out);
	return out;
}

/*std::istream& operator>>(std::istream& in, PendulumCard& pen)
{
	pen.set(in);
	return in;
}*/