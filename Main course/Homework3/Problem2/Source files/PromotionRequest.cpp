#include "PromotionRequest.hpp"

std::string PromotionRequest::DEFAULT_MESSAGE = "I want a raise!";

PromotionRequest::PromotionRequest(const std::string& sender, double amount)
    : Request(this->DEFAULT_MESSAGE, sender)
{
    this->amount = amount;
}

PromotionRequest& PromotionRequest::operator=(const PromotionRequest& toCopy)
{
    this->Request::operator=(toCopy);
    this->amount = toCopy.amount;

    return* this;
}

double PromotionRequest::getAmount() const
{
    return this->amount;
}
