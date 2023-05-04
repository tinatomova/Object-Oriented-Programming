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
#include "MagicCard.hpp"
#include "MonsterCard.hpp"
class PendulumCard : public Card,public MonsterCard, public MagicCard
{
private:
	unsigned int scale;
public:
	PendulumCard& operator=(const PendulumCard& rhs);
	PendulumCard();
	PendulumCard(std::string n, std::string e,unsigned int r, unsigned int a, unsigned int p, unsigned int s,Type t);
	unsigned int getScale()const;
	void setScale(unsigned int s);
	virtual void print(std::ostream& out)const;
	virtual void set(std::istream& in);

	//friend std::ostream& operator<<(std::ostream& out, const MonsterCard& monster);
	//friend std::istream& operator>>(std::istream& in, MonsterCard& monster);
};
//std::ostream& operator<<(std::ostream& out, const MonsterCard& monster);
//std::istream& operator>>(std::istream& in, MonsterCard& monster);
