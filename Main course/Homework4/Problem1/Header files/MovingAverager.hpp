#pragma once

#include "Averager.hpp"

// MovingAverager is a type of Subscriber, which saves data
// and returns the average of the last `windowSize` number of
// data points when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class MovingAverager : public Averager
{
public:
	MovingAverager(const std::string& id, size_t windowSize);

	// windowSize specifies how many most-recent data points
	// should be saved
	// Should never be changed once initialized
	const size_t windowSize;

	// read calculates the average of the last windowSize number
	// of data points
	// returns 0 if there's no data points
	int read() const override;

	Averager* clone() const override;

private:
};
