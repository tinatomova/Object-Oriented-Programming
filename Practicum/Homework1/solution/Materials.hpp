#pragma once
#include <iostream>
using namespace std;
class Materials
{
private:
	 int herbs;
	 int ores;
	 int cloth;
	 int essence;
	 
public:
	Materials();
	bool setMaterials(int h, int o, int c, int e);
	bool isEmpty()const;
	bool isFull()const;
	bool add(Materials& M);
	bool remove(Materials& to_remove);
	void clear();
	bool isTooMuch(int h, int o, int c, int e)const;
	int getSlots();
	int getHerbs();
	int getOres();
	int getCloth();
	int getEssence();

	//void print();
};