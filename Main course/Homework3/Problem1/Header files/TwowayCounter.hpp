#pragma once

#include "Counter.hpp"

class TwowayCounter : public Counter
{
public:
	TwowayCounter();
	TwowayCounter(int initial);
	TwowayCounter(int initial, unsigned step);

	void decrement();
};