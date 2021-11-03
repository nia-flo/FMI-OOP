#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* averager)
{
	this->SimplePublisher::subscribe(averager);

	for (auto message : this->oldMessages)
	{
		averager->signal(message);
	}
}

void BacklogPublisher::signal(const Message& message)
{
	this->SimplePublisher::signal(message);

	this->oldMessages.push_back(message);
}
