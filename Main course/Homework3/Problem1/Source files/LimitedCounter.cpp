#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max)
	: Counter()
{
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial)
	: Counter(initial)
{
	this->max = max;
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step)
	: Counter(initial, step)
{
	this->max = max;
}

void LimitedCounter::increment()
{
	if (this->value + (int)(this->step) <= this->max)
	{
		this->value += this->step;
	}
}

int LimitedCounter::getMax() const
{
	return this->max;
}
