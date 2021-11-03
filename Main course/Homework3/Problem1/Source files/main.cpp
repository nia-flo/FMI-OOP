#include <iostream>

#include "Semaphore.hpp"

int main()
{
	std::cout << "Counter:\n";
	Counter counter(1, 5);
	std::cout << counter.getTotal() << ' ' << counter.getStep() << '\n';
	counter.increment();
	std::cout << counter.getTotal() << ' ' << counter.getStep() << '\n';

	std::cout << '\n';

	std::cout << "TwowayCounter:\n";
	TwowayCounter twoWayCounter(17);
	std::cout << twoWayCounter.getTotal() << ' ' << twoWayCounter.getStep() << '\n';
	twoWayCounter.increment();
	std::cout << twoWayCounter.getTotal() << ' ' << twoWayCounter.getStep() << '\n';
	twoWayCounter.decrement();
	twoWayCounter.decrement();
	std::cout << twoWayCounter.getTotal() << ' ' << twoWayCounter.getStep() << '\n';

	std::cout << '\n';

	std::cout << "LimitedCounter:\n";
	LimitedCounter limitedCounter(20, 9, 5);
	std::cout << limitedCounter.getTotal() << ' ' << limitedCounter.getStep() << ' ' << limitedCounter.getMax() << '\n';
	limitedCounter.increment();
	std::cout << limitedCounter.getTotal() << ' ' << limitedCounter.getStep() << ' ' << limitedCounter.getMax() << '\n';
	limitedCounter.increment();
	std::cout << limitedCounter.getTotal() << ' ' << limitedCounter.getStep() << ' ' << limitedCounter.getMax() << '\n';
	limitedCounter.increment();
	std::cout << limitedCounter.getTotal() << ' ' << limitedCounter.getStep() << ' ' << limitedCounter.getMax() << '\n';

	std::cout << '\n';

	std::cout << "LimitedTwowayCounter:\n";
	LimitedTwowayCounter limitedTwowayCounter(-1, 2, 1);
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';
	limitedTwowayCounter.increment();
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';
	limitedTwowayCounter.increment();
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';
	limitedTwowayCounter.decrement();
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';
	limitedTwowayCounter.decrement();
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';
	limitedTwowayCounter.decrement();
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';
	limitedTwowayCounter.decrement();
	std::cout << limitedTwowayCounter.getTotal() << ' ' << limitedTwowayCounter.getStep() << ' ' << limitedTwowayCounter.getMax() << ' ' << limitedTwowayCounter.getMin() << '\n';

	std::cout << '\n';

	std::cout << "Semaphore\n";
	Semaphore semaphore;
	std::cout << semaphore.isAvailable() << '\n';
	semaphore.wait();
	std::cout << semaphore.isAvailable() << '\n';
	semaphore.wait();
	std::cout << semaphore.isAvailable() << '\n';
	semaphore.signal();
	std::cout << semaphore.isAvailable() << '\n';
	semaphore.signal();
	std::cout << semaphore.isAvailable() << '\n';

	return 0;
}