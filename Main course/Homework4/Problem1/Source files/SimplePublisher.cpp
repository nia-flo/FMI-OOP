#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager* averager)
{
	for (auto subscriber : this->subscribers)
	{
		if (subscriber->id == averager->id)
		{
			return;
		}
	}

	this->subscribers.push_back(averager);
}

void SimplePublisher::unsubscribe(Averager* averager)
{
	for (int i = 0; i < this->subscribers.size(); i++)
	{
		if (this->subscribers[i]->id == averager->id)
		{
			this->subscribers.erase(this->subscribers.begin() + i);
			return;
		}
	}
}

void SimplePublisher::signal(const Message& message)
{
	for (auto subscriber : this->subscribers)
	{
		subscriber->signal(message);
	}
}
