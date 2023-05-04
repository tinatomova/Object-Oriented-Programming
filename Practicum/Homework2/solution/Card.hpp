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

#pragma once
#include<iostream>
#include<fstream>
#include <string>

class Card
{
protected:
	std::string name;
	std::string effect;

public:
	Card();
	Card(std::string n, std::string e);
	Card(const Card& c);

	void setName(std::string n);
	void setEffect(std::string e);
	std::string getName()const;
	std::string getEffect()const;

	Card& operator=(const Card& rhs);

	virtual void print(std::ostream& out)const;
	virtual void set(std::istream& in);

	friend std::ostream& operator<<(std::ostream& out, const Card& card);
	friend std::istream& operator>>(std::istream& in, Card& card);
};
std::ostream& operator<<(std::ostream& out, const Card& card);
std::istream& operator>>(std::istream& in, Card& card);
