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

#include "Card.hpp"

#include <fstream>

class MonsterCard : public virtual Card
{
public:
	// Constructors
	MonsterCard();
	MonsterCard(const std::string& name, const std::string& effect, unsigned rarity, unsigned attackPoints, unsigned defencePoints);

	// Accessors
	unsigned GetAttackPoints() const;
	unsigned GetDefencePoints() const;

	// Operations
	Card* Copy() const override;

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, const MonsterCard& card);
	friend std::istream& operator>>(std::istream& stream, MonsterCard& card);

protected:
	// Constants
	static const int DEFAULT_ATTACK_POINTS = 0;
	static const int DEFAULT_DEFENCE_POINTS = 0;

	// Properties
	unsigned attackPoints;
	unsigned defencePoints;
};