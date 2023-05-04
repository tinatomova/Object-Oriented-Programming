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

#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period): Subscriber(id), period(period){}

int PeriodicSampler::read()const
{
	if (vec.empty() == 1)return 0;
	for (int i = vec.size() - 1; i >= 0; i--) {
		if (i % period == 0)return vec[i].data;
	}
	return 0;
}

void PeriodicSampler::signal(const Message& m)
{
	add(m);
}

Subscriber* PeriodicSampler::copy() const
{
	return new PeriodicSampler(*this);
}

