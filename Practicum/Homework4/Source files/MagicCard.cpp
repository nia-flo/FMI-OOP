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

#include "MagicCard.hpp"
#include "HelperFunctions.h"

#include <algorithm>
#include <vector>

MagicCard::MagicCard()
{
	this->type = this->DEFAULT_TYPE;
}

MagicCard::MagicCard(const std::string& name, const std::string& effect, unsigned rarity, Type type)
	: Card(name, effect, rarity)
{
	this->type = type;
}

Type MagicCard::GetType() const
{
	return this->type;
}

Card* MagicCard::Copy() const
{
	return new MagicCard(*this);
}

std::string MagicCard::GetTypeAsString() const
{
	switch (this->type)
	{
	case Type::buff:
		return "buff";
	case Type::spell:
		return "spell";
	case Type::trap:
		return "trap";
	case Type::unknown:
		return "unknown";
	}
}

std::ostream& operator<<(std::ostream& stream, const MagicCard& card)
{
	stream << card.name << '|' << card.effect << '|' << card.rarity << '|' << card.GetTypeAsString();

	return stream;
}

std::istream& operator>>(std::istream& stream, MagicCard& card)
{
	std::string line;
	std::getline(stream, line);

	std::vector<std::string> splittedLine = HelperFunctions::SplitLine(line, '|');

	card = HelperFunctions::CreateMagicCard(splittedLine);

	return stream;
}
