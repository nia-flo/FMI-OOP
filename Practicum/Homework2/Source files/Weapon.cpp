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

#include "Weapon.h"

#include <sstream>
#include <iomanip>

Weapon Weapon::NewAxe(WeaponType type, std::pair<unsigned int, unsigned int> hitDamage)
{
	Weapon weapon(type, WeaponKind::axe, hitDamage);

	return weapon;
}

Weapon Weapon::NewSword(WeaponType type, std::pair<unsigned int, unsigned int> hitDamage)
{
	Weapon weapon(type, WeaponKind::sword, hitDamage);

	return weapon;
}

Weapon Weapon::NewDagger(std::pair<unsigned int, unsigned int> hitDamage)
{
	Weapon weapon(WeaponType::one_handed, WeaponKind::dagger, hitDamage);

	return weapon;
}

Weapon Weapon::NewMace(WeaponType type, std::pair<unsigned int, unsigned int> hitDamage)
{
	Weapon weapon(type, WeaponKind::mace, hitDamage);

	return weapon;
}

Weapon Weapon::NewStaff(std::pair<unsigned int, unsigned int> hitDamage)
{
	Weapon weapon(WeaponType::two_handed, WeaponKind::staff, hitDamage);

	return weapon;
}

Weapon& Weapon::operator=(const Weapon& weapon)
{
	this->kind = weapon.kind;
	this->type = weapon.type;
	this->hitDamage = weapon.hitDamage;
	this->effects = weapon.effects;

	return *this;
}

WeaponKind Weapon::GetKind() const
{
	return this->kind;
}

WeaponType Weapon::GetType() const
{
	return this->type;
}

std::pair<unsigned int, unsigned int> Weapon::GetHitDamage() const
{
	return this->hitDamage;
}

std::vector<std::pair<std::string, double>> Weapon::GetEffects() const
{
	std::vector<std::pair<std::string, double>> effectsVector;

	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		effectsVector.push_back(*effect);
	}

	return effectsVector;
}

double Weapon::WeaponScore() const
{
	double weaponScore = (double)(this->hitDamage.first + this->hitDamage.second) / 2;

	double effectsSum = 0;
	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		effectsSum += (*effect).second;
	}

	if (this->type == WeaponType::one_handed)
	{
		weaponScore += effectsSum * this->ONE_HANDED_COEFFICIENT;
	}
	else
	{
		weaponScore += effectsSum * this->TWO_HANDED_COEFFICIENT;
	}

	return weaponScore;
}

int Weapon::UsedSlots() const
{
	if (this->type == WeaponType::one_handed)
	{
		return this->ONE_HANDED_USED_SLOTS;
	}

	return this->TWO_HANDED_USED_SLOTS;
}

bool Weapon::ChangeType(WeaponType type)
{
	if (this->kind == WeaponKind::staff)
	{
		return (type == WeaponType::two_handed);
	}

	if (this->kind == WeaponKind::dagger)
	{
		return (type == WeaponType::one_handed);
	}

	this->type = type;

	return true;
}

bool Weapon::ChangeKind(WeaponKind kind)
{
	if (kind == WeaponKind::staff)
	{
		if (this->type == WeaponType::two_handed)
		{
			this->kind = kind;
			return true;
		}

		return false;
	}

	if (kind == WeaponKind::dagger)
	{
		if (this->type == WeaponType::one_handed)
		{
			this->kind = kind;
			return true;
		}

		return false;
	}

	this->kind = kind;

	return true;
}

bool Weapon::AddEffect(const std::string& name, double power)
{
	if (power <= 0)
	{
		return false;
	}

	this->effects[name] = power;

	return true;
}

bool Weapon::RemoveEffect(const std::string& name)
{
	for (std::map<std::string, double>::iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		if ((*effect).first == name)
		{
			this->effects.erase(effect);
			return true;
		}
	}

	return false;
}

std::string Weapon::ToString() const
{
	std::string str = "Weapon\n";

	str += "Type: ";
	switch (this->type)
	{
	case WeaponType::one_handed:
		str += "one handed";
		break;
	case WeaponType::two_handed:
		str += "two handed";
	}
	str += "\n";


	str += "Kind: ";
	switch (this->kind)
	{
	case WeaponKind::axe:
		str += "axe";
		break;
	case WeaponKind::dagger:
		str += "dagger";
		break;
	case WeaponKind::mace:
		str += "mace";
		break;
	case WeaponKind::staff:
		str += "staff";
		break;
	case WeaponKind::sword:
		str += "sword";
		break;
	}
	str += "\n";

	str += "Hit damage: minimal " + std::to_string(this->hitDamage.first) + " ; maximal " + std::to_string(this->hitDamage.second) + "\n";

	str += "Effects:\n";
	for (std::map<std::string, double>::const_iterator effect = this->effects.begin(); effect != this->effects.end(); effect++)
	{
		str += "name: " + (*effect).first + " ; power: " + std::to_string((*effect).second) + "\n";
	}

	std::ostringstream scoreStream;
	scoreStream << std::fixed << std::setprecision(2) << this->WeaponScore();

	str += "Weapon score: " + scoreStream.str() + "\n";

	return str;
}


Weapon::Weapon(WeaponType type, WeaponKind kind, std::pair<unsigned int, unsigned int> hitDamage)
{
	this->type = type;
	this->kind = kind;
	this->hitDamage = hitDamage;
}
