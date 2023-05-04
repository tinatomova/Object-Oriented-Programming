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

#include "Duelist.hpp"

Duelist::Duelist(std::string n)
{
    name = n;
    d;
}

Deck& Duelist::getDeck()
{
    return d;
}

bool Duelist::addDuelistFromFile(const char* filename)
{
	std::ifstream inFile(filename);
	if (inFile.is_open()) {
		inFile >> *this;

	}
	else return 0;

	inFile.close();
	return 1;

}

bool Duelist::insertDuelistInFile(const char* filename) const
{
	std::ofstream outFile(filename);
	if (outFile.is_open()) {
		outFile << *this;

	}
	else return 0;
	outFile.close();
	return 1;
}

std::istream& operator>>(std::istream& in, Duelist& duelist)
{
	in >> duelist.d;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Duelist& duelist)
{
	out << duelist.d;
	return out;
}
