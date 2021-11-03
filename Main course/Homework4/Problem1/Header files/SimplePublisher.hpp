#pragma once

#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher 
{
public:
	// subscribe registers a Subscriber to start receiving messages
	virtual void subscribe(Averager*);

	// unsubscribe removes a Subscriber from the Publisher
	// Subscribers are removed based on their `id`
	// id's will always be unique
	void unsubscribe(Averager*);

	// signal receives a message from an external source
	// and replays that message to all the current subscribers
	virtual void signal(const Message&);

private:
	std::vector<Averager*> subscribers;
};
