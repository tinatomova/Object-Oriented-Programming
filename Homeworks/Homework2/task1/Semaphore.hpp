#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore:public LimitedTwowayCounter
{
public:
	Semaphore();
	Semaphore(bool initial);

	bool isAvailable();
	void wait();
	void signal();
};
