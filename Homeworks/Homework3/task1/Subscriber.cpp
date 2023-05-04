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

#include "Subscriber.hpp"

Subscriber::Subscriber(std::string id):id(id){}

void Subscriber::add(Message m)
{
	vec.push_back(m);
}

int Subscriber::messages()
{
	return vec.size();
}

Message Subscriber::get(int i) const
{
	return vec[i];
}


