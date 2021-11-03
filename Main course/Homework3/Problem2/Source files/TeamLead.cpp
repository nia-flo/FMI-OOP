#include "TeamLead.hpp"
#include "Developer.hpp"

TeamLead::TeamLead(const std::string& name, double salary)
	: Developer(name)
{
	this->salary = salary;
	this->teamLead = this;
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return this->team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer == nullptr)
	{
		return;
	}

	developer->setInitialSalary(salary);
	developer->setTeamLead(this);

	this->team.push_back(developer);
}

void TeamLead::removeDeveloperFromTeam(const std::string& name)
{
	for (int i = this->team.size() - 1; i >= 0; i--)
	{
		if (this->team[i]->getName() == name)
		{
			this->team[i]->setTeamLead(nullptr);
			this->team.erase(this->team.begin() + i);
			return;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < this->team.size(); i++)
	{
		this->team[i]->increaseSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < this->team.size(); i++)
	{
		this->team[i]->decreaseSalary(amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	this->leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	this->promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	while (!leavingRequests.empty())
	{
		this->removeDeveloperFromTeam(leavingRequests[0].getSender());
		leavingRequests.erase(leavingRequests.begin());
	}
}

void TeamLead::fulfillPromotionRequests()
{
	while (!this->promotionRequests.empty())
	{
		for (int i = 0; i < this->team.size(); i++)
		{
			if (this->team[i]->getName() == this->promotionRequests[0].getSender())
			{
				this->team[i]->increaseSalary(this->promotionRequests[0].getAmount());
				break;
			}
		}

		this->promotionRequests.erase(this->promotionRequests.begin());
	}
}
