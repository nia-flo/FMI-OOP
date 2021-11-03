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

#include "Card.hpp"

std::string Card::DEFAULT_NAME = "";

std::string Card::DEFAULT_EFFECT = "";

Card::Card()
{
	this->name = this->DEFAULT_NAME;
	this->effect = this->DEFAULT_EFFECT;
	this->rarity = this->DEFAULT_RARITY;
}

Card::~Card() = default;

Card::Card(const std::string& name, const std::string& effect, unsigned rarity)
{
	this->name = name;
	this->effect = effect;
	this->rarity = rarity;
}

const std::string& Card::GetName() const
{
	return this->name;
}

const std::string& Card::GetEffect() const
{
	return this->effect;
}

unsigned Card::GetRarity() const
{
	return this->rarity;
}

bool Card::operator<(const Card& other) const
{
	return this->rarity < other.rarity;
}

bool Card::operator>(const Card& other) const
{
	return this->rarity > other.rarity;
}
