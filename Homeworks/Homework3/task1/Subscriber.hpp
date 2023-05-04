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
#include <string>
#include <vector>
#include "Message.hpp"
class Subscriber
{
public:
	Subscriber(std::string id);
	virtual Subscriber* copy()const = 0;
	void add(Message);
	virtual void signal(const Message&)=0;
	virtual int read()const = 0;
	const std::string id;
	int messages();
	Message get(int)const;
	virtual ~Subscriber() = default;
protected:
	std::vector<Message> vec;
};

