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

#pragma once

#include "PendulumCard.hpp"

#include <vector>

class Deck
{
public:
	// Constructors
	Deck() = default;
	Deck(std::string name);

	// Accessors
	std::vector<MagicCard> GetMagicCards() const;
	std::vector<MonsterCard> GetMonsterCards() const;
	std::vector<PendulumCard> GetPendulumCards() const;

	// Mutators
	void SetName(std::string name);

	// Operations
	int MagicCardsCount() const;
	int MonsterCardsCount() const;
	int PendulumCardsCount() const;
	void AddMagicCard(const MagicCard& magicCard);
	void AddMonsterCard(const MonsterCard& monsterCard);
	void AddPendulumCard(const PendulumCard& pendulumCard);
	void ChangeMagicCard(const MagicCard magicCard, int index);
	void ChangeMonsterCard(const MonsterCard monsterCard, int index);
	void ChangePendulumCard(const PendulumCard pendulumCard, int index);
	void Clear();

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, Deck& deck);
	friend std::istream& operator>>(std::istream& stream, Deck& deck);

private:
	// Constants
	static const int MONSTER_CARD_PROPERTIES_IN_FILE_COUNT = 4;
	static const int MAGIC_CARD_PROPERTIES_IN_FILE_COUNT = 3;
	static const int PENDELUM_CARD_PROPERTIES_IN_FILE_COUNT = 6;

	// Properties
	std::string name;
	std::vector<MonsterCard> monsterCards;
	std::vector<MagicCard> magicCards;
	std::vector<PendulumCard> pendulumCards;
};

