#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const std::string& id, size_t windowSize)
	: Averager(id),
	  windowSize(windowSize)
{
}

int MovingAverager::read() const
{
	if (this->messages.size() < this->windowSize || this->windowSize == 0)
	{
		return this->Averager::read();
	}

	int sum = 0;
	for (int i = 0; i < this->windowSize; i++)
	{
		sum += this->messages[this->messages.size() - i - 1].data;
	}
	return sum / this->windowSize;
}

Averager* MovingAverager::clone() const
{
	return new MovingAverager(*this);
}
