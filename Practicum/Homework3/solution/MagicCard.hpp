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

#pragma once
#include "Card.hpp"
#include<iostream>
#include<fstream>
enum Type {
	DEFAULT,
	trap,
	buff,
	spell
};
class MagicCard :public Card
{
protected:
	Type type;
public:
	MagicCard();
	MagicCard(std::string n, std::string e,unsigned int r, Type t);
	MagicCard(const MagicCard& magic);
	MagicCard& operator=(const MagicCard& rhs);
	std::string getType()const;
	void setType(Type t);
	virtual void print(std::ostream& out) const;
	virtual void set(std::istream& in);

	//friend std::ostream& operator<<(std::ostream& out, const MagicCard& magic);
	//friend std::istream& operator>>(std::istream& in, MagicCard& magic);

};
//std::ostream& operator<<(std::ostream& out, const MagicCard& magic);
//std::istream& operator>>(std::istream& in, MagicCard& magic);
bool isletter(char a);