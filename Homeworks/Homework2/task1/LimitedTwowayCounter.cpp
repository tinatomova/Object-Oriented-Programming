#include"LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max) :LimitedCounter(max), TwowayCounter(), Counter()
{
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial):LimitedCounter(max,initial),TwowayCounter(initial), Counter(initial)
{
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned int step):LimitedCounter(max,initial,step), TwowayCounter(initial,step), Counter(initial,step)
{
	this->min = min;
}

void LimitedTwowayCounter::increment()
{
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
	if (int(value) - int(step) >= min) {
		TwowayCounter::decrement();
	}

}

int LimitedTwowayCounter::getMin() const
{
	return min;
}

