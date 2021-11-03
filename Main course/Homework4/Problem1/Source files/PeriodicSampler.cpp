#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const std::string& id, size_t period)
	: Averager(id),
	  period(period)
{
	this->signalsCount = this->INITIAL_SIGNALS_COUNT;
}

int PeriodicSampler::read() const
{
	if (this->messages.size() == 0 || this->period == 0)
	{
		return 0;
	}

	if (this->messages.size() <= this->period)
	{
		return this->messages[0].data;
	}

	return this->messages[this->messages.size() - 1 - (this->messages.size() - 1) % this->period].data;
}

Averager* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}
