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

#include "Card.hpp"

#include <fstream>

class MonsterCard : public Card
{
public:
	// Constructors
	MonsterCard();
	MonsterCard(std::string name, std::string effect, unsigned int attackPoints, unsigned int defencePoints);

	// Accessors
	unsigned int GetAttackPoints() const;
	unsigned int GetDefencePoints() const;

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, MonsterCard& card);

protected:
	// Constants
	static const int DEFAULT_ATTACK_POINTS = 0;
	static const int DEFAULT_DEFENCE_POINTS = 0;

	// Properties
	unsigned int attackPoints;
	unsigned int defencePoints;
};