#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max):Counter()
{
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial):Counter(initial)
{
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned int step):Counter(initial,step)
{
	this->max = max;
}

LimitedCounter::LimitedCounter(const LimitedCounter& rhs) : Counter(rhs)
{
	this->max = rhs.max;
}

void LimitedCounter::increment()
{
	if (int(value) + int(step) <= max) {
		Counter::increment();
	}
	
}

int LimitedCounter::getMax() const
{
	return max;
}

