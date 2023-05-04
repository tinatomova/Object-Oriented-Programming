#pragma once


template<typename T>
class Backpack
{
private:
	T backpack;
	int slots;
	
public:
	int getSlots();
	bool isEmpty() const;
	bool isFull() const;
	void clear();
	void add(T& to_add);
	void remove(T to_remove);
	void setSlots();
	void print();
};

template<typename T>
inline int Backpack<T>::getSlots()
{
	return backpack.getSlots();
}

template<typename T>
inline bool Backpack<T>::isEmpty() const
{
	return (backpack.isEmpty() == 1);
	
}

template<typename T>
inline bool Backpack<T>::isFull() const
{
	return (backpack.isFull() == 1);
	
}

template<typename T>
inline void Backpack<T>::clear()
{
	backpack.clear();
	slots = 0;
}

template<typename T>
inline void Backpack<T>::add(T& to_add)
{
	backpack.add(to_add);
	setSlots();
}

template<typename T>
inline void Backpack<T>::remove(T to_remove)
{
	backpack.remove(to_remove);
	setSlots();
}

template<typename T>
inline void Backpack<T>::setSlots()
{
	slots = backpack.getSlots();
	
}

template<typename T>
inline void Backpack<T>::print()
{
	backpack.print();
}
