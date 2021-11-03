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

#include "Backpack.h"
#include "Equipment.h"

#include <ostream>

template <typename T>
class Inventory
{
public:
	// Constructors
	Inventory(T&);

	// Operators
	Inventory& operator=(const Inventory&) = default;
	bool operator==(const Inventory&) const;
	bool operator!=(const Inventory&) const;

	// Accessors
	const T& GetContent() const;

	// Operations
	void ChangeContent(T&);
	bool Add(MaterialType, unsigned int); // adding Materials to Backpack - returns true if the opperation is successful, otherwise - false
	bool Add(unsigned int, unsigned int); // adding Money to Backpack - returns true if the opperation is successful, otherwise - false
	bool Add(const Armor&); // adding Armor to Equipment - returns true if the opperation is successful, otherwise - false
	bool Add(const Weapon&); // adding Weapon to Equipment - returns true if the opperation is successful, otherwise - false
	bool Remove(MaterialType); // removing Materials from Backpack - returns true if the opperation is successful, otherwise - false
	bool Remove(unsigned int, unsigned int); // removing Money from Backpack - returns true if the opperation is successful, otherwise - false
	bool Remove(WeaponKind); // removing Weapon from Equipment - returns true if the opperation is successful, otherwise - false
	bool Remove(ArmorType); // removing Armor from Equipment - returns true if the opperation is successful, otherwise - false

	// Friend functions
	friend std::ostream& operator<<(std::ostream& output, Inventory<T>& inventory)
	{
		output << "=== Inventory ===\n" << inventory.content.ToString();

		return output;
	}

private:
	// Properties
	T content;
};

template<typename T>
Inventory<T>::Inventory(T& content)
{
	this->content = content;
}

template<typename T>
bool Inventory<T>::operator==(const Inventory& other) const
{
	return this->content.UsedSlotsCount() == other.content.UsedSlotsCount();
}

template<typename T>
bool Inventory<T>::operator!=(const Inventory& other) const
{
	return !(*this == other);
}

template<typename T>
const T& Inventory<T>::GetContent() const
{
	return this->content;
}

template<typename T>
void Inventory<T>::ChangeContent(T& content)
{
	this->content = content;
}

template<>
bool Inventory<Backpack<Materials>>::Add(MaterialType type, unsigned int quantity)
{
	return this->content.Add(type, quantity);
}

template<>
inline bool Inventory<Backpack<Money>>::Add(unsigned int gold, unsigned int silver)
{
	return this->content.Add(gold, silver);
}

template<>
inline bool Inventory<Equipment<Armor>>::Add(const Armor& armor)
{
	return this->content.Add(armor);
}

template<>
inline bool Inventory<Equipment<Weapon>>::Add(const Weapon& weapon)
{
	return this->content.Add(weapon);
}

template<>
bool Inventory<Backpack<Materials>>::Remove(MaterialType type)
{
	return this->content.Remove(type);
}

template<>
bool Inventory<Backpack<Money>>::Remove(unsigned int gold, unsigned int silver)
{
	return this->content.Remove(gold, silver);
}

template<>
bool Inventory<Equipment<Weapon>>::Remove(WeaponKind kind)
{
	return this->content.Remove(kind);
}

template<>
bool Inventory<Equipment<Armor>>::Remove(ArmorType type)
{
	return this->content.Remove(type);
}