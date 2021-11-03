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

#pragma once

#include "Deck.hpp"

class Duelist
{
public:
	Duelist(); //Default Constructor
	Duelist(const char* name); //Constructor
	Duelist(const Duelist&); //Copy constructor

	Duelist& operator=(const Duelist&); //Copy assignment operator

	~Duelist(); //Destructor

	//Operations
	int MagicCardsInDeckCount();
	int MonsterCardsInDeckCount();
	void AddMagicCardInDeck(const MagicCard&);
	void AddMonsterCardInDeck(const MonsterCard&);
	void ChangeMagicCardInDeck(const MagicCard, int);
	void ChangeMonsterCardInDeck(const MonsterCard, int);

private:
	//Properties
	char* name;
	Deck deck;

	//Mutators
	void SetName(const char*);

	//Operations
	void Copy(const Duelist&);
};

