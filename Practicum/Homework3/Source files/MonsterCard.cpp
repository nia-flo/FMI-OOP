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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard()
{
	this->attackPoints = this->DEFAULT_ATTACK_POINTS;
	this->defencePoints = this->DEFAULT_DEFENCE_POINTS;
}

MonsterCard::MonsterCard(std::string name, std::string effect, unsigned int attackPoints, unsigned int defencePoints)
	: Card (name, effect)
{
	this->attackPoints = attackPoints;
	this->defencePoints = defencePoints;
}

unsigned int MonsterCard::GetAttackPoints() const
{
	return this->attackPoints;
}

unsigned int MonsterCard::GetDefencePoints() const
{
	return this->defencePoints;
}

std::ostream& operator<<(std::ostream& stream, MonsterCard& card)
{
	stream << card.name << '|' << card.effect << '|' << card.attackPoints << '|' << card.defencePoints;

	return stream;
}
