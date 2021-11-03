#include "Counter.hpp"

Counter::Counter()
{
	this->value = this->DEFAULT_INITIAL_VALUE;
	this->step = this->DEFAULT_STEP;
}

Counter::Counter(int initial)
{
	this->value = initial;
	this->step = this->DEFAULT_STEP;
}

Counter::Counter(int initial, unsigned step)
{
	this->value = initial;
	this->step = step;
}

void Counter::increment()
{
	this->value += this->step;
}

int Counter::getTotal() const
{
	return this->value;
}

unsigned Counter::getStep() const
{
	return this->step;
}
