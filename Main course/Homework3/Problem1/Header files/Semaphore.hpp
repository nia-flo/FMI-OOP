#pragma once

#include "LimitedTwowayCounter.hpp"

class Semaphore : private LimitedTwowayCounter
{
public:
	Semaphore();
	Semaphore(bool initial);

	bool isAvailable() const;
	void wait();
	void signal();

private:
	static const int MIN = 0;
	static const int MAX = 1;
};