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

#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Subscriber* s)
{
	for (unsigned int i = 0; i < mes.size(); i++) {
		s->signal(mes[i]);
	}
	subs.push_back(s);
}

void BacklogPublisher::signal(const Message& m)
{
	mes.push_back(m);
	for (unsigned int i = 0; i < subs.size(); i++) {
		subs[i]->signal(m);
	}
	
}

