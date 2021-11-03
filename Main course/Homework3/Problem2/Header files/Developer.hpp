#pragma once

#include <string>

class TeamLead;

class Developer
{
public:
	Developer(const std::string& name);

	std::string getName() const;
	double getSalary() const;
	const TeamLead* getTeamLead() const;

	void setTeamLead(TeamLead* teamLead);
	void setInitialSalary(double amount);
	void increaseSalary(double amount);
	void decreaseSalary(double amount);
	void sendLeavingRequest() const;
	void sendPromotionRequest(double amount) const;


protected:
	static const int DEFAULT_SALARY = 0;

	std::string name;
	double salary;
	TeamLead* teamLead;
};