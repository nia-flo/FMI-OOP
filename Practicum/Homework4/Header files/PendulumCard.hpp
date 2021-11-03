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

#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard
	: public MonsterCard,
	  public MagicCard
{
public:
	// Constructors
	PendulumCard();
	PendulumCard(const std::string& name, const std::string& effect, unsigned rarity, unsigned attackPoints, unsigned defencePoints,
		short pendelumScale, Type type);
	PendulumCard(const PendulumCard& pendulumCard);

	// Accessors
	short GetPendelumScale() const;

	// Operations
	Card* Copy() const override;

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, const PendulumCard& card);
	friend std::istream& operator>>(std::istream& stream, PendulumCard& card);

private:
	// Constants
	static const int DEFAULT_PENDELUM_SCALE = 1;
	static const int MIN_PENDELUM_SCALE = 1;
	static const int MAX_PENDELUM_SCALE = 13;

	// Properties
	short pendelumScale; // number between 1 and 13

	// Mutators
	void SetPendelumScale(short value);
};