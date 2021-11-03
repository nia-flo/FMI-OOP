#include <iostream>

#include "TeamLead.hpp"

int main()
{
	Developer pesho1("Pesho");
	std::cout << pesho1.getName() << ' ' << pesho1.getSalary() << ' ' << pesho1.getTeamLead() << '\n';

	pesho1.setInitialSalary(150.67);
	std::cout << pesho1.getName() << ' ' << pesho1.getSalary() << ' ' << pesho1.getTeamLead() << "\n\n";

	Developer ivan("Ivan");
	std::cout << ivan.getName() << ' ' << ivan.getSalary() << ' ' << ivan.getTeamLead() << "\n\n";

	Developer pesho2("Pesho");
	std::cout << pesho2.getName() << ' ' << pesho2.getSalary() << ' ' << pesho2.getTeamLead() << "\n\n";

	TeamLead teamLead("Maria", 800);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' '<< dev->getSalary() << '\n';
	}
	std::cout << '\n';

	teamLead.addDeveloperToTeam(&pesho1, 800);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	std::cout << pesho1.getName() << ' ' << pesho1.getSalary() << ' ' << pesho1.getTeamLead() << "\n\n";

	teamLead.addDeveloperToTeam(&ivan, 800);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	std::cout << ivan.getName() << ' ' << ivan.getSalary() << ' ' << ivan.getTeamLead() << "\n\n";

	teamLead.addDeveloperToTeam(&pesho2, 980);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	std::cout << pesho2.getName() << ' ' << pesho2.getSalary() << ' ' << pesho2.getTeamLead() << "\n\n";

	teamLead.decreaseTeamSalariesBy(50);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	teamLead.increaseTeamSalariesBy(200);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	teamLead.removeDeveloperFromTeam("Milica");
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	teamLead.removeDeveloperFromTeam("Pesho");
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	std::cout << pesho2.getName() << ' ' << pesho2.getSalary() << ' ' << pesho2.getTeamLead() << "\n\n";

	teamLead.addDeveloperToTeam(&pesho2, 980);
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	std::cout << pesho2.getName() << ' ' << pesho2.getSalary() << ' ' << pesho2.getTeamLead() << "\n\n";

	pesho1.sendLeavingRequest();
	ivan.sendLeavingRequest();

	teamLead.fulfillLeavingRequests();
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	pesho1.sendPromotionRequest(300);

	teamLead.fulfillPromotionRequests();
	std::cout << teamLead.getName() << ' ' << teamLead.getSalary() << '\n';
	for (Developer* dev : teamLead.getTeam())
	{
		std::cout << dev->getName() << ' ' << dev->getSalary() << '\n';
	}
	std::cout << '\n';

	return 0;
}