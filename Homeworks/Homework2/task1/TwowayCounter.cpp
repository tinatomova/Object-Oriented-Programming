#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter():Counter()
{

}
TwowayCounter::TwowayCounter(int initial) : Counter(initial)
{

}
TwowayCounter::TwowayCounter(int initial, unsigned int step) : Counter(initial, step)
{

}
TwowayCounter::TwowayCounter(const TwowayCounter& rhs) : Counter(rhs)
{

}
void TwowayCounter::decrement()
{
	value -= step;
}

