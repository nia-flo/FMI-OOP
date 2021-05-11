#include "ElectionResultsDatabase.hpp"

#include <iostream>

int main ()
{
	ElectionResultsDatabase db;
	db.addResultsFromFile("example.txt");
	std::cout << db.votesForParty(PARTY1) << '\n'; // ����� 50
	std::cout << db.votesForParty(PARTY2) << '\n'; // ����� 60
	std::cout << db.votesForParty(PARTY3) << '\n'; // ����� 40
	std::cout << db.winningParty() << '\n'; // ����� PARTY2
	std::cout << db.numberOfSections() << '\n'; // ����� 5

	return 0;
}