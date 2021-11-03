#pragma once

#include "Message.hpp"

#include <string>
#include <vector>

// Averager is a type of Subscriber, which saves data and
// returns the average of the data when `read()` is called.
// Data is provided with the `signal()` method.
// Average of N numbers = sum(all numbers) / N
class Averager 
{
public:
	Averager(const std::string& id);

	// id is a unique identifier for a Subscriber
	// Should never be changed once initialized
	const std::string id;

	// signal adds a new data point
	void signal(const Message&);

	// read calculates the average of all data points provided so far
	// returns 0 if there's no data points
	virtual int read() const;

	virtual Averager* clone() const;

protected:
	std::vector<Message> messages;
};
