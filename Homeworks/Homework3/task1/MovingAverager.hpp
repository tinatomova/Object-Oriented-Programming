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
#include "Subscriber.hpp"

class MovingAverager : public Subscriber{
public:
	const size_t windowSize;

	MovingAverager(std::string id, size_t windowSize);
	int read()const;
	void signal(const Message&);
	Subscriber* copy()const;
};
