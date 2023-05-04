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
#include<iostream>
#include<fstream>
#include "Card.hpp"
class MonsterCard : public Card
{
protected:
	unsigned int attackingPoints;
	unsigned int protectingPoints;
public:
	MonsterCard();
	MonsterCard(std::string n, std::string e,unsigned int r, unsigned int a, unsigned int p);
	MonsterCard(const MonsterCard& monster);
	MonsterCard& operator=(const MonsterCard& rhs);
	unsigned int getAPoints()const;
	unsigned int getPPoints()const;
	void setAPoints(unsigned int a);
	void setPPoints(unsigned int p);
	virtual void print(std::ostream& out)const;
	virtual void set(std::istream& in);

	//friend std::ostream& operator<<(std::ostream& out, const MonsterCard& monster);
	//friend std::istream& operator>>(std::istream& in, MonsterCard& monster);
};

//std::ostream& operator<<(std::ostream& out, const MonsterCard& monster);
//std::istream& operator>>(std::istream& in, MonsterCard& monster);