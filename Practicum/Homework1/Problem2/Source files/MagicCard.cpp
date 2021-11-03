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
#pragma warning(disable : 26812)

#include "MagicCard.hpp"

#include <cstring>

//public functions

MagicCard::MagicCard() //Default Constructor
{
	strcpy(this->name, "");
	strcpy(this->effect, "");
	this->type = Type::unknown;
}

MagicCard::MagicCard(const char* name, const char* effect, Type type) //Constructor
{
	strcpy(this->name, name);
	strcpy(this->effect, effect);
	this->type = type;
}

MagicCard::MagicCard(const MagicCard& magicCard) //Copy constructor
{
	this->Copy(magicCard);
}

MagicCard& MagicCard::operator=(const MagicCard& magicCard) //Copy assignment operator
{
	this->Copy(magicCard);

	return *this;
}

MagicCard::~MagicCard() {} //Destructor

//Accessors

char* MagicCard::GetName()
{
	return this->name;
}

char* MagicCard::GetEffect()
{
	return this->effect;
}

Type MagicCard::GetType()
{
	return this->type;
}

//private functions

//Operations

void MagicCard::Copy(const MagicCard& magicCard)
{
	strcpy(this->name, magicCard.name);
	strcpy(this->effect, magicCard.effect);
	this->type = magicCard.type;
}