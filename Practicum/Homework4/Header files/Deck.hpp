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

#pragma once

#include "PendulumCard.hpp"

#include <vector>

class Deck
{
public:
	// Constructors
	Deck() = default;
	Deck(const std::string& name);
	Deck(const Deck& deck);

	// Destructor
	~Deck();

	// Accessors
	std::vector<MagicCard*> GetMagicCards() const;
	std::vector<MonsterCard*> GetMonsterCards() const;
	std::vector<PendulumCard*> GetPendulumCards() const;
	std::vector<Card*> GetAllCards() const;

	// Mutators
	void SetName(const std::string& name);

	// Operations
	int MagicCardsCount() const;
	int MonsterCardsCount() const;
	int PendulumCardsCount() const;
	int AllCardsCount() const;
	void AddCard(const Card* card);
	bool ChangeCard(const Card* card, int index); // returns true if the card is changed, otherwise - false
	void Clear();
	void Shuffle();

	// Operators
	Deck& operator=(const Deck& deck);
	friend std::ostream& operator<<(std::ostream& stream, const Deck& deck);
	friend std::istream& operator>>(std::istream& stream, Deck& deck);

private:
	// Constants
	static const int MONSTER_CARD_PROPERTIES_IN_FILE_COUNT = 5;
	static const int MAGIC_CARD_PROPERTIES_IN_FILE_COUNT = 4;
	static const int PENDELUM_CARD_PROPERTIES_IN_FILE_COUNT = 7;
	static const int DEFAULT_CARDS_COUNT = 0;

	// Properties
	std::string name;
	std::vector<Card*> cards;
	int magicCardsCount;
	int monsterCardsCount;
	int pendulumCardsCount;

	// Operations
	void Copy(const Deck& deck);
};

