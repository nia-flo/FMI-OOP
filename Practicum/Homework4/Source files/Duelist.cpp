/**
* Solution to homework assignment 4
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

Duelist::Duelist(const std::string& name)
{
	this->name = name;
}

Deck& Duelist::GetDeck()
{
	return this->deck;
}

bool Duelist::SaveDeck(const std::string& fileName)
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

bool Duelist::LoadDeck(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName);

	if (!file.is_open())
	{
		return false;
	}

	file >> *this;

	return true;
}

std::string Duelist::Duel(Duelist& other)
{
	if (this->deck.AllCardsCount() != other.deck.AllCardsCount())
	{
		return "no winner";
	}

	this->deck.Shuffle();
	other.deck.Shuffle();

	std::vector<Card*> thisCards = this->deck.GetAllCards();
	std::vector<Card*> otherCards = other.deck.GetAllCards();

	int thisScore = 0, otherScore = 0;
	for (int i = 0; i < thisCards.size(); i++)
	{
		if (thisCards[i] > otherCards[i])
		{
			thisScore++;
		}
		else if (thisCards[i] < otherCards[i])
		{
			otherScore++;
		}
	}

	if (thisScore > otherScore)
	{
		return this->name;
	}

	if (thisScore < otherScore)
	{
		return other.name;
	}

	return "no winner";
}

std::string Duel(Duelist& first, Duelist& second)
{
	return first.Duel(second);
}

std::ostream& operator<<(std::ostream& stream, const Duelist& duelist)
{
	stream << duelist.deck;

	return stream;
}

std::istream& operator>>(std::istream& stream, Duelist& duelist)
{
	stream >> duelist.deck;

	return stream;
}
