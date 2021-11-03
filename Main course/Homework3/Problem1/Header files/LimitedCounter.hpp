#pragma once

#include "Counter.hpp"

class LimitedCounter : public Counter
{
public:
	LimitedCounter(int max);
	LimitedCounter(int max, int initial);
	LimitedCounter(int max, int initial, unsigned step);

	void increment() override;
	int getMax() const;

protected:
	int max;
};