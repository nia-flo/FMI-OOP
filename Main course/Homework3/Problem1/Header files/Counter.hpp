#pragma once

class Counter
{
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);

	virtual void increment();
	virtual int getTotal() const;
	virtual unsigned getStep() const;

protected:
	const int DEFAULT_INITIAL_VALUE = 0;
	const int DEFAULT_STEP = 1;

	int value;
	unsigned step;
};