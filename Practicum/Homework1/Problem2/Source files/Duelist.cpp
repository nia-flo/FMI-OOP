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

#pragma warning(disable : 4996)
#pragma warning(disable : 6001)

#include "Duelist.hpp"

#include <cstring>

//public functions

Duelist::Duelist() //Default Constructor
{
	this->SetName("");
}

Duelist::Duelist(const char* name) //Constructor
{
	this->SetName(name);
}

Duelist::Duelist(const Duelist& duelist) //Copy constructor
{
	this->Copy(duelist);
}

Duelist& Duelist::operator=(const Duelist& duelist) //Copy assignment operator
{
	this->Copy(duelist);

	return *this;
}

Duelist::~Duelist() //Destructor
{
	delete[] this->name;
}

//Operations

int Duelist::MagicCardsInDeckCount()
{
	return this->deck.MagicCardsCount();
}

int Duelist::MonsterCardsInDeckCount()
{
	return this->deck.MonsterCardsCount();
}

void Duelist::AddMagicCardInDeck(const MagicCard& magicCard)
{
	this->deck.AddMagicCard(magicCard);
}

void Duelist::AddMonsterCardInDeck(const MonsterCard& monsterCard)
{
	this->deck.AddMonsterCard(monsterCard);
}

void Duelist::ChangeMagicCardInDeck(const MagicCard magicCard, int index)
{
	this->deck.ChangeMagicCard(magicCard, index);
}

void Duelist::ChangeMonsterCardInDeck(const MonsterCard monsterCard, int index)
{
	this->deck.ChangeMonsterCard(monsterCard, index);
}

//private functions

//Mutators

void Duelist::SetName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//Operations

void Duelist::Copy(const Duelist& duelist)
{
	if (this != &duelist)
	{
		this->SetName(duelist.name);
		this->deck = duelist.deck;
	}
}