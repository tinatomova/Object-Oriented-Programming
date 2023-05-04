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
#include"PendulumCard.hpp"
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
class Deck
{
private:
	std::vector<Card*> container;
	
public:
	std::string deckName;
	void setDeckName(std::string n);
	std::string getDeckName();
	unsigned int monsterDeckCount()const;
	unsigned int magicDeckCount()const;
	unsigned int pendulumDeckCount()const;
	unsigned int allCardsCount()const;
	void addCard(Card* card);
	bool changeCard(unsigned int index, Card* card);
	void clear();
	void shuffle();
	Card& getCard(unsigned int i);


	friend std::ostream& operator<<(std::ostream& out, const Deck& deck);
	friend std::istream& operator>>(std::istream& in, Deck& deck);
};
std::ostream& operator<<(std::ostream& out, const Deck& deck);
std::istream& operator>>(std::istream& in, Deck& deck);

int f(int i);