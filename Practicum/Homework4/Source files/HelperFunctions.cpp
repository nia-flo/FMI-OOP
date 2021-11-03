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

#include "HelperFunctions.h"

std::vector<std::string> HelperFunctions::SplitLine(const std::string& line, char separator)
{
	std::vector<std::string> result;

	std::string current;
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == separator) {
			result.push_back(current);
			current = "";

			continue;
		}

		current += line[i];
	}
	result.push_back(current);

	return result;
}

int HelperFunctions::StringToInt(const std::string& number)
{
	int result = 0;

	for (int i = 0; i < number.size(); i++)
	{
		result *= 10;
		result += number[i] - '0';
	}

	return result;
}

MonsterCard HelperFunctions::CreateMonsterCard(const std::vector<std::string>& data)
{
	MonsterCard monsterCard(data[0], data[1], StringToInt(data[2]), StringToInt(data[3]), StringToInt(data[4]));
	return monsterCard;
}

MagicCard HelperFunctions::CreateMagicCard(const std::vector<std::string>& data)
{
	MagicCard magicCard(data[0], data[1], StringToInt(data[2]), GetType(data[3]));
	return magicCard;
}

PendulumCard HelperFunctions::CreatePendulumCard(const std::vector<std::string>& data)
{
	PendulumCard pendulumCard(data[0], data[1], StringToInt(data[2]), StringToInt(data[3]), StringToInt(data[4]), StringToInt(data[5]),
		GetType(data[6]));
	return pendulumCard;
}

Type HelperFunctions::GetType(const std::string& typeString)
{
	if (typeString == "buff")
	{
		return Type::buff;
	}

	if (typeString == "spell")
	{
		return Type::spell;
	}

	if (typeString == "trap")
	{
		return Type::trap;
	}

	return Type::unknown;
}