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
#include "Repository.hpp"

class SimplePublisher {
public:
	std::vector<Subscriber*> subs;
	
	virtual void subscribe(Subscriber*);
	void unsubscribe(Subscriber*);
	void signal(const Message&);
};
