#pragma once
#include <utility>
#include <vector>
#include <string>

template<typename T>
class Equipment
{
private:
	vector<T> equipment;
public:
	int slots;
	Equipment();
	bool isEmpty()const;
	bool isFull()const;
	void clear();
	void add(T& to_add);
	void remove(T& to_remove);
	T bestEquipment();

	bool operator==(const Equipment& e)const;
	bool operator!=(const Equipment& e)const;

};

template<typename T>
inline Equipment<T>::Equipment()
{
	equipment = {};
}

template<typename T>
inline bool Equipment<T>::isEmpty() const
{
	if (slots==0)return 1;
	return 0;
}

template<typename T>
inline bool Equipment<T>::isFull() const
{
	if (slots == 24)return 1;
	return 0;
}

template<typename T>
inline void Equipment<T>::clear()
{
	equipment.clear();
	slots = 0;
}

template<typename T>
inline void Equipment<T>::add(T& to_add)
{
	if (slots+to_add.slots > 24)return;
	equipment.push_back(to_add);
	slots += to_add.slots;

}

template<typename T>
inline void Equipment<T>::remove(T& to_remove)
{
	for (int i = 0; i < equipment.size(); i++) {
		if (equipment.at(i) == to_remove) {
			equipment.erase(equipment.begin() + i);
		}
	}
	if (slots.to_remove == 1)slots--;
	if (slots.to_remove == 2)slots -= 2;

}

template<typename T>
inline T Equipment<T>::bestEquipment()
{
	if (equipment.size() > 0) {
		T best=equipment.at(0);
		for (unsigned int i = 0; i < equipment.size(); i++) {
			if (equipment.at(i) > best)best = equipment.at(i);
		}

		return best;
	}

	
}

template<typename T>
inline bool Equipment<T>::operator==(const Equipment& e) const
{
	T b = bestEquipment();
	T b1 = e.bestEquipment();
	return b == b1;

	
}

template<typename T>
inline bool Equipment<T>::operator!=(const Equipment& e) const
{
	T b = bestEquipment();
	T b1 = e.bestEquipment();
	return b != b1;
}
