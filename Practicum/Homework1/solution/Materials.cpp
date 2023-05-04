#include "Materials.hpp"

Materials::Materials()
{
	herbs = 0;
	ores = 0;
	cloth = 0;
	essence = 0;
}

bool Materials::setMaterials(int h, int o, int c, int e)
{
	if (h < 0 || o < 0 || c < 0 || e < 0)return 0;
	if (isTooMuch(h, o, c, e) == 1)return 0;
	herbs = h;
	ores = o;
	cloth = c;
	essence = e;
	return 1;

}

bool Materials::isEmpty() const
{
	if (herbs == 0 && ores == 0 && cloth == 0 && essence == 0)return 1;
	return 0;
}

bool Materials::isFull() const
{
	if (herbs / 20 + ores / 20 + cloth / 20 + essence / 10 == 16)return 1;
	return 0;
}

bool Materials::add(Materials& M)
{
	int h, o, c, e;
	h = herbs + M.herbs;
	o = ores + M.ores;
	c = cloth + M.cloth;
	e = essence + M.essence;
	if (isTooMuch(h, o, c, e) == 1)return 0;
	else setMaterials(h, o, c, e);
	return 1;

}

 bool Materials::remove(Materials& to_remove)
{
	 int h, o, c, e;
	 h = herbs - to_remove.herbs;
	 o = ores - to_remove.ores;
	 c = cloth - to_remove.cloth;
	 e = essence - to_remove.essence;
	 if (h < 0 || o < 0 || c < 0 || e < 0)return 0;
	 setMaterials(h, o, c, e);
	 return 1;
}

void Materials::clear()
{
	herbs = 0;
	ores = 0;
	cloth = 0;
	essence = 0;
}

bool Materials::isTooMuch(int h, int o, int c, int e) const
{
	int s = 0;
	s = h / 20 + (h % 20 != 0) + o / 20 + (o % 20 != 0) + c / 20 + (c % 20 != 0) + e / 10 + (e % 10 != 0);
	if (s > 16)return 1;
	return 0;
}

int Materials::getSlots()
{
	int s = herbs / 20 + (herbs % 20 != 0) + ores / 20 + (ores % 20 != 0) + cloth / 20 + (cloth % 20 != 0) + essence / 10 + (essence % 10 != 0);
	return s;
}

int Materials::getHerbs()
{
	return herbs;
}

int Materials::getOres()
{
	return ores;
}

int Materials::getCloth()
{
	return cloth;
}

int Materials::getEssence()
{
	return essence;
}

//void Materials::print(){cout << "herbs: " << herbs << "; ores: " << ores << "; cloth: " << cloth << "; essence: " << essence << endl;}
