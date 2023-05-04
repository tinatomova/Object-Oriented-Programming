/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Tina Tomova
* @idnumber 62594
* @task 1
* @compiler VC
*/

#include "Averager.hpp"

Averager::Averager(std::string id): Subscriber(id){}

int Averager::read()const
{
	if (vec.empty() == 1)return 0;
	int sum = 0;
	for (unsigned int i = 0; i < vec.size(); i++) {
		sum += vec[i].data;
	}
	return sum / vec.size();
}

void Averager::signal(const Message& m)
{
	
}

Subscriber* Averager::copy() const
{
	return new Averager(*this);
}

