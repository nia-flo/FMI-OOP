#include "ElectionResultsDatabase.hpp"

#include <iostream>

int main ()
{
	ElectionResultsDatabase db;
	db.addResultsFromFile("example.txt");
	std::cout << db.votesForParty(PARTY1) << '\n'; // връща 50
	std::cout << db.votesForParty(PARTY2) << '\n'; // връща 60
	std::cout << db.votesForParty(PARTY3) << '\n'; // връща 40
	std::cout << db.winningParty() << '\n'; // връща PARTY2
	std::cout << db.numberOfSections() << '\n'; // връща 5

	return 0;
}