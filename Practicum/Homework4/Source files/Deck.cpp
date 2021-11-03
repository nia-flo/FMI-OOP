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

#include "Deck.hpp"
#include "HelperFunctions.h"

#include <algorithm>

Deck::Deck(const std::string& name)
{
	this->name = name;
}

Deck::Deck(const Deck& deck)
{
	this->Copy(deck);
}

Deck::~Deck()
{
	for (auto card : this->cards)
	{
		delete card;
	}
}

std::vector<MagicCard*> Deck::GetMagicCards() const
{
	std::vector<MagicCard*> result;
	for (auto card : this->cards)
	{
		MagicCard* magicCard = dynamic_cast<MagicCard*>(card);
		if (magicCard && !(dynamic_cast<PendulumCard*>(card)))
		{
			result.push_back(magicCard);
		}
	}

	return result;
}

std::vector<MonsterCard*> Deck::GetMonsterCards() const
{
	std::vector<MonsterCard*> result;
	for (auto card : this->cards)
	{
		MonsterCard* monsterCard = dynamic_cast<MonsterCard*>(card);
		if (monsterCard && !(dynamic_cast<PendulumCard*>(card)))
		{
			result.push_back(monsterCard);
		}
	}

	return result;
}

std::vector<PendulumCard*> Deck::GetPendulumCards() const
{
	std::vector<PendulumCard*> result;
	for (auto card : this->cards)
	{
		PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(card);
		if (pendulumCard)
		{
			result.push_back(pendulumCard);
		}
	}

	return result;
}

std::vector<Card*> Deck::GetAllCards() const
{
	return this->cards;
}

void Deck::SetName(const std::string& name)
{
	this->name = name;
}

int Deck::MagicCardsCount() const
{
	return this->magicCardsCount;
}

int Deck::MonsterCardsCount() const
{
	return this->monsterCardsCount;
}

int Deck::PendulumCardsCount() const
{
	return this->pendulumCardsCount;
}

int Deck::AllCardsCount() const
{
	return this->cards.size();
}

void Deck::AddCard(const Card* card)
{
	Card* toAdd = card->Copy();
	this->cards.push_back(toAdd);

	PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(toAdd);
	if (pendulumCard)
	{
		this->pendulumCardsCount++;
		return;
	}

	MonsterCard* monsterCard = dynamic_cast<MonsterCard*>(toAdd);
	if (monsterCard)
	{
		this->monsterCardsCount++;
		return;
	}

	this->magicCardsCount++;
}

bool Deck::ChangeCard(const Card* card, int index)
{
	if (index < 0 || index >= this->cards.size())
	{
		return false;
	}

	Card* toChange = card->Copy();

	PendulumCard* pendulumCard = dynamic_cast<PendulumCard*>(toChange);
	if (pendulumCard)
	{
		if (!dynamic_cast<PendulumCard*>(this->cards[index]))
		{
			delete toChange;
			return false;
		}

		delete this->cards[index];
		this->cards[index] = toChange;

		return true;
	}

	MagicCard* magicCard = dynamic_cast<MagicCard*>(toChange);
	if (magicCard)
	{
		if (!dynamic_cast<MagicCard*>(this->cards[index]))
		{
			delete toChange;
			return false;
		}

		delete this->cards[index];
		this->cards[index] = toChange;

		return true;
	}

	if (!dynamic_cast<MonsterCard*>(this->cards[index]))
	{
		delete toChange;
		return false;
	}

	delete this->cards[index];
	this->cards[index] = toChange;

	return true;

}

void Deck::Clear()
{
	this->~Deck();
	this->cards.clear();
	this->magicCardsCount = this->DEFAULT_CARDS_COUNT;
	this->magicCardsCount = this->DEFAULT_CARDS_COUNT;
	this->pendulumCardsCount = this->DEFAULT_CARDS_COUNT;
}

void Deck::Shuffle()
{
	std::random_shuffle(this->cards.begin(), this->cards.end());
}

Deck& Deck::operator=(const Deck& deck)
{
	if (this != &deck)
	{
		this->~Deck();
		this->Copy(deck);
	}

	return *this;
}

void Deck::Copy(const Deck& deck)
{
	this->name = deck.name;

	for (auto card : deck.cards)
	{
		this->cards.push_back(card->Copy());
	}

	this->magicCardsCount = deck.magicCardsCount;
	this->monsterCardsCount = deck.monsterCardsCount;
	this->pendulumCardsCount = deck.pendulumCardsCount;
}

std::ostream& operator<<(std::ostream& stream, const Deck& deck)
{
	stream << deck.name << '|' << deck.AllCardsCount() << '|' << deck.MonsterCardsCount() << '|' << deck.MagicCardsCount() << '|'
		<< deck.PendulumCardsCount() << '\n';

	for (auto card : deck.GetMonsterCards())
	{
		stream << *card << '\n';
	}

	for (auto card : deck.GetMagicCards())
	{
		stream << *card << '\n';
	}

	for (auto card : deck.GetPendulumCards())
	{
		stream << *card << '\n';
	}

	return stream;
}

std::istream& operator>>(std::istream& stream, Deck& deck)
{
	deck.Clear();

	std::string line;
	std::getline(stream, line);

	std::string name;
	for (int i = 0; line[i] != '|'; i++)
	{
		name += line[i];
	}

	deck.name = name;

	while (std::getline(stream, line))
	{
		std::vector<std::string> splittedLine = HelperFunctions::SplitLine(line, '|');

		if (splittedLine.size() == deck.MONSTER_CARD_PROPERTIES_IN_FILE_COUNT)
		{
			deck.AddCard(&(HelperFunctions::CreateMonsterCard(splittedLine)));
			continue;
		}

		if (splittedLine.size() == deck.MAGIC_CARD_PROPERTIES_IN_FILE_COUNT)
		{
			deck.AddCard(&(HelperFunctions::CreateMagicCard(splittedLine)));
			continue;
		}

		if (splittedLine.size() == deck.PENDELUM_CARD_PROPERTIES_IN_FILE_COUNT)
		{
			deck.AddCard(&(HelperFunctions::CreatePendulumCard(splittedLine)));
			continue;
		}
	}

	return stream;
}
