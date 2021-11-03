#pragma once

#include "Request.hpp"

class LeavingRequest : public Request
{
public:
	LeavingRequest(const std::string& sender);

	LeavingRequest& operator=(const LeavingRequest& toCopy);

private:
	static std::string DEFAULT_MESSAGE;

};