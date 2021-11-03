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

enum class Type
{
	trap,
	buff,
	spell,
	unknown
};

class MagicCard : public virtual Card
{
public:
	// Constructors
	MagicCard();
	MagicCard(const std::string& name, const std::string& effect, unsigned rarity, Type type);

	// Accessors
	Type GetType() const;

	// Operations
	Card* Copy() const override;

	// Operators
	friend std::ostream& operator<<(std::ostream& stream, const MagicCard& card);
	friend std::istream& operator>>(std::istream& stream, MagicCard& card);

protected:
	// Constants
	static const Type DEFAULT_TYPE = Type::unknown;

	// Properties
	Type type;

	// Operations
	std::string GetTypeAsString() const;
};