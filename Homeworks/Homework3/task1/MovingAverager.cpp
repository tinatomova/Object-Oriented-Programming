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

#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize): Subscriber(id), windowSize(windowSize){}

int MovingAverager::read()const
{
	if (vec.empty() == 1)return 0;
	if (windowSize == 0)return 0;
	int sum = 0;
	for (size_t i = vec.size() - 1; i > vec.size() - windowSize - 1; i--) {
		sum += vec[i].data;
	}
	return sum / windowSize;
}

void MovingAverager::signal(const Message& m)
{
	add(m);
}

Subscriber* MovingAverager::copy() const
{
	return new MovingAverager(*this);
}

