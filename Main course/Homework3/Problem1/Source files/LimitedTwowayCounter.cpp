#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max)
	: LimitedCounter(max)
{
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial)
	: LimitedCounter(max, initial)
{
	this->min = min;
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step)
	: LimitedCounter(max, initial, step)
{
	this->min = min;
}

void LimitedTwowayCounter::increment()
{
	this->LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
	if (this->LimitedCounter::value - (int)(this->LimitedCounter::step) >= this->min)
	{
		this->LimitedCounter::value -= this->LimitedCounter::step;
	}
}

int LimitedTwowayCounter::getMin() const
{
	return this->min;
}

int LimitedTwowayCounter::getTotal() const
{
	return this->LimitedCounter::value;
}

unsigned LimitedTwowayCounter::getStep() const
{
	return this->LimitedCounter::step;
}
