#include "Developer.hpp"
#include "TeamLead.hpp"
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

Developer::Developer(const std::string& name)
{
	this->name = name;
	this->salary = this->DEFAULT_SALARY;
	this->teamLead = nullptr;
}

std::string Developer::getName() const
{
	return this->name;
}

double Developer::getSalary() const
{
	return this->salary;
}

const TeamLead* Developer::getTeamLead() const
{
	return this->teamLead;
}

void Developer::setTeamLead(TeamLead* teamLead)
{
	this->teamLead = teamLead;
}

void Developer::setInitialSalary(double amount)
{
	if (this->salary == this->DEFAULT_SALARY)
	{
		this->salary = amount;
	}
}

void Developer::increaseSalary(double amount)
{
	this->salary += amount;
}

void Developer::decreaseSalary(double amount)
{
	this->salary -= amount;

	if (this->salary < this->DEFAULT_SALARY)
	{
		this->salary = this->DEFAULT_SALARY;
	}
}

void Developer::sendLeavingRequest() const
{
	if (this->teamLead != nullptr)
	{
		this->teamLead->addLeavingRequest(LeavingRequest((this->name)));
	}
}

void Developer::sendPromotionRequest(double amount) const
{
	if (this->teamLead != nullptr)
	{
		this->teamLead->addPromotionRequest(PromotionRequest(this->name, amount));
	}
}
