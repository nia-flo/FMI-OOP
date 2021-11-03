#include "Request.hpp"

int Request::requestsCount = 0;

Request::Request(const std::string& message, const std::string& sender)
{
	this->message = message;
	this->sender = sender;

	this->requestsCount++;
	this->ID = this->requestsCount;
}

Request& Request::operator=(const Request& toCopy)
{
	this->message = toCopy.message;
	this->sender = toCopy.sender;
	this->ID = toCopy.ID;

	return *this;
}

std::string Request::getMessage() const
{
	return this->message;
}

std::string Request::getSender() const
{
	return this->sender;
}

int Request::getCount() const
{
	return this->requestsCount;
}

int Request::getID() const
{
	return this->ID;
}
