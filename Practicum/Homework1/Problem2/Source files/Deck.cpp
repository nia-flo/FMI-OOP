/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Stefania Tsvetkova
* @idnumber 62573
* @task 2
* @compiler VC
*/

#pragma warning(disable : 6385)

#include "Deck.hpp"

//public functions

Deck::Deck() //Default Constructor
{
	for (int i = 0; i < this->MAX_MONSTER_CARD_COUNT; i++)
	{
		this->isThereMonsterCard[i] = false;
	}
}

Deck::Deck(const Deck& deck) //Copy Constructor
{
	this->Copy(deck);
}

Deck& Deck::operator=(const Deck& deck) //Copy assignment operator
{
	this->Copy(deck);

	return *this;
}

Deck::~Deck() {} //Destructor

//Accessors

MagicCard* Deck::GetMagicCards()
{
	MagicCard* allCards = new MagicCard[this->MagicCardsCount()];

	for (int i = 0, added = 0; i < this->MAX_MAGIC_CARD_COUNT; i++)
	{
		if (this->magicCards[i].GetType() != Type::unknown)
		{
			allCards[added] = this->magicCards[i];
			added++;
		}
	}

	return allCards;
}

MonsterCard* Deck::GetMonsterCards()
{
	MonsterCard* allCards = new MonsterCard[this->MonsterCardsCount()];

	for (int i = 0, added = 0; i < this->MAX_MONSTER_CARD_COUNT; i++)
	{
		if (this->isThereMonsterCard[i])
		{
			allCards[added] = this->monsterCards[i];
			added++;
		}
	}

	return allCards;
}

//Operations

int Deck::MagicCardsCount()
{
	int count = 0;
	for (int i = 0; i < this->MAX_MAGIC_CARD_COUNT; i++)
	{
		if (this->magicCards[i].GetType() != Type::unknown) {
			count++;
		}
	}

	return count;
}

int Deck::MonsterCardsCount()
{
	int count = 0;
	for (int i = 0; i < this->MAX_MONSTER_CARD_COUNT; i++)
	{
		if (this->isThereMonsterCard[i]) {
			count++;
		}
	}

	return count;
}

void Deck::AddMagicCard(const MagicCard& magicCard)
{
	for (int i = 0; i < this->MAX_MAGIC_CARD_COUNT; i++)
	{
		if (this->magicCards[i].GetType() == Type::unknown)
		{
			this->magicCards[i] = magicCard;
			return;
		}
	}
}

void Deck::AddMonsterCard(const MonsterCard& monsterCard)
{
	for (int i = 0; i < this->MAX_MONSTER_CARD_COUNT; i++)
	{
		if (!this->isThereMonsterCard[i])
		{
			this->monsterCards[i] = monsterCard;
			this->isThereMonsterCard[i] = true;
			return;
		}
	}
}

void Deck::ChangeMagicCard(const MagicCard magicCard, int index)
{
	this->magicCards[index] = magicCard;
}

void Deck::ChangeMonsterCard(const MonsterCard monsterCard, int index)
{
	this->monsterCards[index] = monsterCard;
	this->isThereMonsterCard[index] = true;
}

//private functions

//Operations

void Deck::Copy(const Deck& deck) {
	for (int i = 0; i < MAX_MONSTER_CARD_COUNT; i++)
	{
		this->monsterCards[i] = deck.monsterCards[i];
		this->isThereMonsterCard[i] = deck.isThereMonsterCard[i];
	}

	for (int i = 0; i < MAX_MAGIC_CARD_COUNT; i++)
	{
		this->magicCards[i] = deck.magicCards[i];
	}
}