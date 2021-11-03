/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefania Tsvetkova
* @idnumber 62573
* @task 1
* @compiler VC
*/

#include "Duelist.hpp"

#include <fstream>

Duelist::Duelist(std::string name)
{
	this->name = name;
}

Deck& Duelist::GetDeck()
{
	return this->deck;
}

bool Duelist::SaveDeck(std::string fileName)
{
	std::ofstream file;
	file.open(fileName, std::ios::trunc);

	if (!file.is_open())
	{
		return false;
	}

	file << *this;

	return true;
}

bool Duelist::LoadDeck(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file >> this->deck;

	return true;
}

std::ostream& operator<<(std::ostream& stream, Duelist& duelist)
{
	stream << duelist.deck;

	return stream;
}
