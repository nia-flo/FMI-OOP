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

#pragma once

#include "Armor.h"
#include "Weapon.h"

#include <vector>
#include <iostream>

template <typename T>
class Equipment
{
public:
	// Operators
	Equipment<T>& operator=(const Equipment<T>&) = default;
	bool operator==(const Equipment<T>&);
	bool operator!=(const Equipment<T>&);

	// Accessors
	std::vector<T> GetContent() const;

	// Operations
	bool IsEmpty() const; // returns true if the opperation is successful, otherwise - false
	bool IsFull() const; // returns true if the opperation is successful, otherwise - false
	void Clear(); // removes everything from the equipment
	bool Add(const T&); // returns true if the opperation is successful, otherwise - false
	bool Remove(WeaponKind); // removing Weapon - returns true if the opperation is successful, otherwise - false
	bool Remove(ArmorType); // removing Armor - returns true if the opperation is successful, otherwise - false
	std::pair<bool, T&> Best() const; // if equipment is empty, .first is false, otherwise .first is true and .second is the best equipment
	int UsedSlotsCount() const;
	std::string ToString() const;

private:
	// Constants
	static const int slots = 24;

	// Properties
	std::vector<T> content;
};

template<>
bool Equipment<Armor>::operator==(const Equipment<Armor>& other)
{
	if (!this->Best().first)
	{
		return !other.Best().first;
	}

	if (!other.Best().first)
	{
		return false;
	}

	return this->Best().second.Gearscore() == other.Best().second.Gearscore();
}

template<>
bool Equipment<Weapon>::operator==(const Equipment<Weapon>& other)
{
	if (!this->Best().first)
	{
		return !other.Best().first;
	}

	if (!other.Best().first)
	{
		return false;
	}

	return this->Best().second.WeaponScore() == other.Best().second.WeaponScore();
}

template<typename T>
bool Equipment<T>::operator!=(const Equipment<T>& other)
{
	return !(*this == other);
}

template<typename T>
std::vector<T> Equipment<T>::GetContent() const
{
	return this->content;
}

template<typename T>
bool Equipment<T>::IsEmpty() const
{
	return this->content.size() == 0;
}

template<typename T>
bool Equipment<T>::IsFull() const
{
	return this->UsedSlotsCount() == this->slots;
}

template<typename T>
void Equipment<T>::Clear()
{
	this->content.clear();
}

template<typename T>
bool Equipment<T>::Add(const T& toAdd)
{
	if (this->UsedSlotsCount() + toAdd.UsedSlots() <= this->slots)
	{
		this->content.push_back(toAdd);
		return true;
	}

	return false;
}

template<typename T>
bool Equipment<T>::Remove(WeaponKind kind)
{
	if (typeid(T) == typeid(Armor))
	{
		return false;
	}

	bool removed = false;
	for (int i = 0; i < this->content.size(); i++)
	{
		if (this->content[i].Weapon::GetKind() == kind)
		{
			this->content.erase(this->content.begin() + i);
			removed = true;
			i--;
		}
	}

	return removed;
}

template<typename T>
bool Equipment<T>::Remove(ArmorType type)
{
	if (typeid(T) == typeid(Weapon))
	{
		return false;
	}

	bool removed = false;
	for (int i = 0; i < this->content.size(); i++)
	{
		if (this->content[i].Armor::GetType() == type)
		{
			this->content.erase(this->content.begin() + i);
			removed = true;
			i--;
		}
	}

	return removed;
}

template<>
std::pair<bool, Armor&> Equipment<Armor>::Best() const
{
	if (this->content.size() == 0)
	{
		Armor empty;
		return { false, empty };
	}

	int bestIdx = 0;
	for (int i = 1; i < this->content.size(); i++)
	{
		if (this->content[i].Gearscore() > this->content[bestIdx].Gearscore())
		{
			bestIdx = i;
		}
	}

	return { true, (Armor&)(this->content[bestIdx]) };
}

template<>
std::pair<bool, Weapon&> Equipment<Weapon>::Best() const
{
	if (this->content.size() == 0)
	{
		Weapon empty;
		return { false, empty };
	}

	int bestIdx = 0;
	for (int i = 1; i < this->content.size(); i++)
	{
		if (this->content[i].WeaponScore() > this->content[bestIdx].WeaponScore())
		{
			bestIdx = i;
		}
	}

	return { true, (Weapon&)(this->content[bestIdx]) };
}

template<>
int Equipment<Armor>::UsedSlotsCount() const
{
	return this->content.size();
}

template<>
int Equipment<Weapon>::UsedSlotsCount() const
{
	int usedSlots = 0;
	for (int i = 0; i < this->content.size(); i++)
	{
		usedSlots += this->content[i].UsedSlots();
	}

	return usedSlots;
}

template<typename T>
std::string Equipment<T>::ToString() const
{

	std::string str = "--- Equipment ---\n";

	if (this->content.size() == 0)
	{
		str += "empty\n";
		return str;
	}

	for (int i = 0; i < this->content.size(); i++)
	{
		str += "#" + std::to_string(i + 1) + " ";
		str += this->content[i].ToString();
		str += "\n";
	}

	return str;
}
