
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
#include <string>

class Card
{
protected:
	std::string name;
	std::string effect;
	unsigned int rarity;

public:
	Card();
	Card(std::string n, std::string e, unsigned int r);
	Card(const Card& c);
	virtual ~Card() = 0;

	void setName(std::string n);
	void setEffect(std::string e);
	void setRarity(unsigned int r);
	std::string getName()const;
	std::string getEffect()const;
	unsigned int getRarity()const;

	Card& operator=(const Card& rhs);
	bool operator<(const Card& rhs)const;
	bool operator>(const Card& rhs)const;

	virtual void print(std::ostream& out)const;
	virtual void set(std::istream& in);

	friend std::ostream& operator<<(std::ostream& out, const Card& card);
	friend std::istream& operator>>(std::istream& in, Card& card);
};
std::ostream& operator<<(std::ostream& out, const Card& card);
std::istream& operator>>(std::istream& in, Card& card);