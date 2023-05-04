#include "Money.hpp"

void Money::setMoney(int s, int g)
{
	if (s < 0 || g < 0)return;
	silver = s % 100;
	g += s / 100;
	gold = g;	
}

Money::Money()
{
	silver = 0;
	gold = 0;
}

int Money::getSilver()
{
	return silver;
}

int Money::getGold()
{
	return gold;
}

bool Money::isEmpty() const
{
	if (gold == 0 && silver == 0)return 1;
	return 0;
}

bool Money::isFull() const
{
	return 0;
}

void Money::add(Money& to_add)
{
	int s = 0, g = 0;
	s = silver + to_add.silver;
	g = gold + to_add.gold;
	setMoney(s, g);

}

bool Money::remove(Money& to_remove)
{
	int s = (gold * 100 + silver) - ((to_remove.gold) * 100 + to_remove.silver);
	if (s >= 0) {
		setMoney(s, 0);
		return 1;
	}
	return 0;
}

void Money::clear()
{
	silver = 0;
	gold = 0;
}

int Money::getSlots()
{
	return 0;
}

//void Money::print()
//{
//	cout << "gold: " << gold << "; silver: " << silver << endl;
//}
