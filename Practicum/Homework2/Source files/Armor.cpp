/**
*Solution to homework assignment 2
*Object Oriented Programming Course
*Faculty of Mathematics and Informatics of Sofia University
*Summer semester 2020/2021
 *
*@author Stefania Tsvetkova
*@idnumber 62573
*@task 1
*@compiler VC
*/

#include "Armor.h"

#include <sstream>
#include <iomanip>

Armor::Armor(ArmorType type, unsigned int defence)
{
	this->type = type;
	this->defence = defence;
}

ArmorType Armor::GetType() const
{
	return this->type;
}

unsigned int Armor::GetDefence() const
{
	return this->defence;
}

std::vector<std::pair<std::string, double>> Armor::GetEffects() const
{
	std::vector<std::pair<std::string, double>> effectsVector;

	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		effectsVector.push_back(*effect);
	}

	return effectsVector;
}

double Armor::Gearscore() const
{
	double gearscore = 0;

	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		gearscore += (*effect).second;
	}

	return gearscore;
}

int Armor::UsedSlots() const
{
	return this->USED_SLOTS;
}

bool Armor::AddEffect(const std::string& name, double power)
{
	if (power <= 0)
	{
		return false;
	}

	this->effects[name] = power;

	return true;
}

bool Armor::RemoveEffect(const std::string& name)
{
	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		if ((*effect).first == name)
		{
			this->effects.erase(effect);
			return true;
		}
	}

	return false;
}

std::string Armor::ToString() const
{
	std::string str = "Armor:\n";

	str += "Type: ";
	switch (this->type)
	{
	case ArmorType::cloth:
		str += "cloth";
		break;
	case ArmorType::leather:
		str += "leather";
		break;
	case ArmorType::mail:
		str += "mail";
		break;
	}
	str += "\n";

	str += "Defence: " + std::to_string(this->defence) + "\n";

	str += "Effects:\n";
	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		str += "name: " + (*effect).first + " ; power: " + std::to_string((*effect).second) + "\n";
	}

	std::ostringstream scoreStream;
	scoreStream << std::fixed << std::setprecision(2) << this->Gearscore();

	str += "Gear score: " + scoreStream.str() + "\n";

	return str;
}
