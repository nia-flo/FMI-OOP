#include "LeavingRequest.hpp"

std::string LeavingRequest::DEFAULT_MESSAGE = "I want to leave!";

LeavingRequest::LeavingRequest(const std::string& sender)
	: Request(this->DEFAULT_MESSAGE, sender)
{
}

LeavingRequest& LeavingRequest::operator=(const LeavingRequest& toCopy)
{
	this->Request::operator=(toCopy);

	return*this;
}
