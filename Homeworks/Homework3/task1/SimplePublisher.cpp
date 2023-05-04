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

#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Subscriber* s)
{
	subs.push_back(s);
}

void SimplePublisher::unsubscribe(Subscriber* s)
{
	for (unsigned int i = 0; i < subs.size(); i++) {
		if (s->id == subs[i]->id) {
			subs.erase(subs.begin() + i);
		}
	}
}

void SimplePublisher::signal(const Message& m)
{
	for (unsigned int i = 0; i < subs.size(); i++) {
		subs[i]->signal(m);
	}
	
}

