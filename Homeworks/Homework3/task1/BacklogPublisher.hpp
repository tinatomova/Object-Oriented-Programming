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

#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "SimplePublisher.hpp"
#include "Repository.hpp"

class BacklogPublisher : public SimplePublisher{
public:
	void signal(const Message&);
	void subscribe(Subscriber*);	
private:
	std::vector<Message> mes;
};
