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

#include "MonsterCard.hpp"
#include"MagicCard.hpp"

class Deck
{
public:
	Deck(); //Default Constructor
	Deck(const Deck&); //Copy Constructor

	Deck& operator=(const Deck&); //Copy assignment operator

	~Deck(); //Destructor

	//Accessors
	MagicCard* GetMagicCards();
	MonsterCard* GetMonsterCards();

	//Operations
	int MagicCardsCount();
	int MonsterCardsCount();
	void AddMagicCard(const MagicCard&);
	void AddMonsterCard(const MonsterCard&);
	void ChangeMagicCard(const MagicCard, int);
	void ChangeMonsterCard(const MonsterCard, int);

private:
	//Constants
	static const int MAX_MONSTER_CARD_COUNT = 20;
	static const int MAX_MAGIC_CARD_COUNT = 20;

	//Properties
	MonsterCard monsterCards[MAX_MONSTER_CARD_COUNT];
	bool isThereMonsterCard[MAX_MONSTER_CARD_COUNT];
	MagicCard magicCards[MAX_MAGIC_CARD_COUNT];

	//Operations
	void Copy(const Deck&);
};

