#pragma once
#include <iostream>
using namespace std;
class Money
{
private:
	int silver, gold;
	int slots = 0;
public:
	Money();
	int getSilver();
	int getGold();
	void setMoney(int s, int g);
	bool isEmpty()const;
	bool isFull()const;
	void add(Money&);
	bool remove(Money&);
	void clear();
	int getSlots();

	//void print();
};
