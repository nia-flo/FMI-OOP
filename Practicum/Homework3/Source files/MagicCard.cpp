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

#include "MagicCard.hpp"

MagicCard::MagicCard()
{
	this->type = this->DEFAULT_TYPE;
}

MagicCard::MagicCard(std::string name, std::string effect, Type type)
	: Card(name, effect)
{
	this->type = type;
}

Type MagicCard::GetType() const
{
	return this->type;
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

std::ostream& operator<<(std::ostream& stream, MagicCard& card)
{
	stream << card.name << '|' << card.effect << '|' << card.GetTypeAsString();

	return stream;
}
