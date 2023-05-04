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
#include "Deck.hpp"
#include<iostream>
#include<fstream>
class Duelist
{
private:
	std::string name;
	Deck d;
public:
	Duelist(std::string n);
	Deck& getDeck();
	bool addDuelistFromFile(const char* filename);
	bool insertDuelistInFile(const char* filename)const;
	void duel(Duelist& other);

	friend std::ostream& operator<<(std::ostream& out, const Duelist& duelist);
	friend std::istream& operator>>(std::istream& in, Duelist& duelist);
};
std::ostream& operator<<(std::ostream& out, const Duelist& duelist);
std::istream& operator>>(std::istream& in, Duelist& duelist);