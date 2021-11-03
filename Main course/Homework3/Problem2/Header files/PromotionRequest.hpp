#pragma once

#include "Request.hpp"

class PromotionRequest : public Request
{
public:
	PromotionRequest(const std::string& sender, double amount);

	PromotionRequest& operator=(const PromotionRequest& toCopy);

	double getAmount() const;

private:
	static std::string DEFAULT_MESSAGE;

	double amount;

};