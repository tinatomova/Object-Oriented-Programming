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

#include "Repository.hpp"

Repository::Repository(const Repository& r)
{
	copy(r);
}

void Repository::copy(const Repository& r) {
	for (auto n : r.subscribers) {
		subscribers.push_back(n->copy());
	}
}

Repository& Repository::operator=(const Repository& r) {
	if (this != &r) {
		del();
		copy(r);
	}
	return *this;
}

void Repository::del() {
	for (auto n : subscribers) {
		delete n;
	}
}

Repository::~Repository() {
	del();
}

void Repository::add(const Subscriber* s)
{
	const Averager *avptr = dynamic_cast<const Averager *>(s);
	if (avptr) {
		subscribers.push_back(new Averager(*avptr));
		return;
	}
	const MovingAverager *mavptr = dynamic_cast<const MovingAverager*>(s);
	if (mavptr) {
		subscribers.push_back(new MovingAverager(*mavptr));
		return;
	}
	const PeriodicSampler* persptr = dynamic_cast<const PeriodicSampler*>(s);
	if (persptr) {
		subscribers.push_back(new PeriodicSampler(*persptr));
	}
}

Subscriber* Repository::get(std::string id)
{
	for (unsigned int i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->id == id) {
			return subscribers[i];
		}
	}
	return nullptr;
}

