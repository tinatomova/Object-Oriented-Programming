#include "Semaphore.hpp"

Semaphore::Semaphore():LimitedTwowayCounter(0,1)
{

}

Semaphore::Semaphore(bool initial):LimitedTwowayCounter(0,1)
{
	if (initial == 1) value = 1;
	
}

bool Semaphore::isAvailable()
{
	if (value == 0)
		return false;
	else return true;
}

void Semaphore::wait()
{
	decrement();
}

void Semaphore::signal()
{
	increment();
}
