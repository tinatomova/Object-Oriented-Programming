#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Inventory
{
private:
	T inventory;
public:
	void add(T& to_add);
	void remove(T& to_remove);
	bool isEmpty()const;
	bool isFull()const;
	void clear();
	void print();

	bool operator==(const Inventory& i)const;
	bool operator!=(const Inventory& i)const;
	//friend ostream& operator<<(ostream& os, const Inventory& I);
};


template<typename T>
inline void Inventory<T>::add(T& to_add)
{
	inventory.add(to_add);
}

template<typename T>
inline void Inventory<T>::remove(T& to_remove)
{
	inventory.remove(to_remove);
}

template<typename T>
inline bool Inventory<T>::isEmpty() const
{
	return (inventory.isEmpty()==1);
}

template<typename T>
inline bool Inventory<T>::isFull() const
{
	return (inventory.isFull()==1);
}

template<typename T>
inline void Inventory<T>::clear()
{
	inventory.clear();
}

template<typename T>
inline void Inventory<T>::print()
{
	inventory.print();
}

template<typename T>
inline bool Inventory<T>::operator==(const Inventory& i) const
{

	if (inventory.getSlots() == i.getSlots())return 1;
	return 0;
}

template<typename T>
inline bool Inventory<T>::operator!=(const Inventory& i) const
{
	if (inventory.slots != i.slots)return 1;
	return 0;
}

//ostream& operator<<(ostream& os, const Inventory& I){}