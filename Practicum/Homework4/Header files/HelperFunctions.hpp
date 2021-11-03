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

#include "PendulumCard.hpp"

#include <vector>
#include <string>

class HelperFunctions
{
public:
	virtual ~HelperFunctions() = 0;

	static std::vector<std::string> SplitLine(const std::string& line, char separator);

	static int StringToInt(const std::string& number);

	static MonsterCard CreateMonsterCard(const std::vector<std::string>& data);

	static MagicCard CreateMagicCard(const std::vector<std::string>& data);

	static PendulumCard CreatePendulumCard(const std::vector<std::string>& data);

private:
	static Type GetType(const std::string& typeString);
};
