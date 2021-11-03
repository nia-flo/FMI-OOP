#pragma once

#include "Averager.hpp"

// PeriodicSampler is a type of Subscriber, which saves every
// period-th data point starting from the first data point provided.
// Data is provided with the `signal()` method.
// 
// e.g if the period = 2, we save every 2nd data point provided
// so if we have
// signal(1), read(), signal(2), read(), signal(3), read(), signal(4), read()
// the output will be 1,1,3,3 as we skip every 2nd data point,
// which in our case is 2 and 4
class PeriodicSampler : public Averager
{
public:
	PeriodicSampler(const std::string& id, size_t period);

	const size_t period;

	// read calculates the average of all data points provided so far
	// returns 0 if there's no data points
	int read() const override;

	Averager* clone() const override;

private:
	const int INITIAL_SIGNALS_COUNT = 0;

	int signalsCount;
};
