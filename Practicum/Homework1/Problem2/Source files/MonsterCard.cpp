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

#pragma warning(disable : 4996)

#include "MonsterCard.hpp"

#include <cstring>

//public functions

MonsterCard::MonsterCard() //Default Constructor
{
	strcpy(this->name, "");
	this->attackPoints = 0;
	this->defencePoints = 0;
}

MonsterCard::MonsterCard(const char* name, unsigned int attackPoints, unsigned int defencePoints) //Constructor
{
	strcpy(this->name, name);
	this->attackPoints = attackPoints;
	this->defencePoints = defencePoints;
}

MonsterCard::MonsterCard(const MonsterCard& monsterCard) //Copy constructor
{
	this->Copy(monsterCard);
}

MonsterCard& MonsterCard::operator=(const MonsterCard& monsterCard) //Copy assignment operator
{
	this->Copy(monsterCard);

	return *this;
}

MonsterCard::~MonsterCard() {} //Destructor

//Accessors

char* MonsterCard::GetName()
{
	return this->name;
}

unsigned int MonsterCard::GetAttackPoints()
{
	return this->attackPoints;
}

unsigned int MonsterCard::GetDefencePoints()
{
	return this->defencePoints;
}

//private functions

//Operations

void MonsterCard::Copy(const MonsterCard& monsterCard)
{
	strcpy(this->name, monsterCard.name);
	this->attackPoints = monsterCard.attackPoints;
	this->defencePoints = monsterCard.defencePoints;
}