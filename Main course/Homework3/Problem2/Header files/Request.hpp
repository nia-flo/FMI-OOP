#pragma once

#include <string>

class Request
{
public:
	Request(const std::string& message, const std::string& sender);

	Request& operator=(const Request& toCopy);

	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;

protected:
	static int requestsCount;

	std::string message;
	std::string sender;
	int ID;
};