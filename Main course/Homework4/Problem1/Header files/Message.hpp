#pragma once

// Message is an abstraction over a simple data point, which
// is sent from a Publisher to a Subscriber
class Message {
public:
	// Constructor
	Message(int data);

	// data is the data point encapsulated in the message
	// Should never be changed once initialized
	const int data;
};
