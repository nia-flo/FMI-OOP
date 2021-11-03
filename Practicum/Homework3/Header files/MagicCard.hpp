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

enum class Type
{
	trap,
	buff,
	spell,
	unknown
};

class MagicCard : public Card
{
public:
	// Constructors
	MagicCard();
	MagicCard(std::string name, std::string effect, Type type);

	// Accessors
	Type GetType() const;

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, MagicCard& card);

protected:
	// Constants
	static const Type DEFAULT_TYPE = Type::unknown;

	// Properties
	Type type;

	// Operations
	std::string GetTypeAsString() const;
};