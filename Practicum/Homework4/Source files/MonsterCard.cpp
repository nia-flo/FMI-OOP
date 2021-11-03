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

#include "MonsterCard.hpp"
#include "HelperFunctions.h"

#include <algorithm>
#include <vector>

MonsterCard::MonsterCard()
{
	this->attackPoints = this->DEFAULT_ATTACK_POINTS;
	this->defencePoints = this->DEFAULT_DEFENCE_POINTS;
}

MonsterCard::MonsterCard(const std::string& name, const std::string& effect, unsigned rarity, unsigned attackPoints, unsigned defencePoints)
	: Card (name, effect, rarity)
{
	this->attackPoints = attackPoints;
	this->defencePoints = defencePoints;
}

unsigned MonsterCard::GetAttackPoints() const
{
	return this->attackPoints;
}

unsigned MonsterCard::GetDefencePoints() const
{
	return this->defencePoints;
}

Card* MonsterCard::Copy() const
{
	return new MonsterCard(*this);
}

std::ostream& operator<<(std::ostream& stream, const MonsterCard& card)
{
	stream << card.name << '|' << card.effect << '|' << card.rarity << '|' << card.attackPoints << '|' << card.defencePoints;

	return stream;
}

std::istream& operator>>(std::istream& stream, MonsterCard& card)
{
	std::string line;
	std::getline(stream, line);

	std::vector<std::string> splittedLine = HelperFunctions::SplitLine(line, '|');

	card = HelperFunctions::CreateMonsterCard(splittedLine);

	return stream;
}
