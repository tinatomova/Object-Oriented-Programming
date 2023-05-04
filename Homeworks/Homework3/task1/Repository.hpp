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
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>
#include <vector>

class Repository {
public:
	std::vector<Subscriber*> subscribers;
	Repository()=default;
	Repository& operator=(const Repository&);
	void copy(const Repository&);
	void del();
	Repository(const Repository&);
	void add(const Subscriber*);
	Subscriber* get(std::string id);
	~Repository();
};
