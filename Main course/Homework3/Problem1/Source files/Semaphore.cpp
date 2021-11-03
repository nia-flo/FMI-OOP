#include "Semaphore.hpp"

Semaphore::Semaphore()
	: LimitedTwowayCounter(MIN, MAX)
{
}

Semaphore::Semaphore(bool initial)
	: LimitedTwowayCounter(MIN, MAX, initial)
{
}

bool Semaphore::isAvailable() const
{
	return this->getTotal() > 0;
}

void Semaphore::wait()
{
	this->decrement();
}

void Semaphore::signal()
{
	this->increment();
}
