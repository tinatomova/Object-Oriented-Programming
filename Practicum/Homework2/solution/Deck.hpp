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
#include "PendulumCard.hpp"
#include <vector>
class Deck
{
private:
	
	std::vector<MonsterCard> monsterDeck;
	std::vector<MagicCard> magicDeck;
	std::vector<PendulumCard> pendulumDeck;
public:
	std::string deckName;
	void setDeckName(std::string n);
	std::string getDeckName();
	unsigned int monsterDeckCount();
	unsigned int magicDeckCount();
	unsigned int pendulumDeckCount();
	void addMonster(const MonsterCard monster);
	void addMagic(const MagicCard magic);
	void addPendulum(const PendulumCard pendulum);
	void changeMonster(unsigned int possition, const MonsterCard monster);
	void changeMagic(unsigned int possition, const MagicCard magic);
	void changePendulum(unsigned int possition, const PendulumCard pendulum);
	void clear();

	friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
	friend std::istream& operator>>(std::istream& in, Deck& deck);
};
std::ostream& operator<<(std::ostream& out, const Deck& deck);
std::istream& operator>>(std::istream& in, Deck& deck);
